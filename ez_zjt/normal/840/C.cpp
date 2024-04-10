#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 310
#define LL long long
#define P 1000000007

inline void update(LL &x,LL y){ x=(x+y)%P; }

bool check(LL x,LL y){
	LL temp=sqrt(x*y)-50;
	for(int i=0;i<100;i++){
		LL z=temp+i;
		if(z*z==x*y) return 1;
	}
	return 0;
}

int n;
LL c[MAXN][MAXN],fac[MAXN];
LL a[MAXN],s[MAXN];
int cnt[MAXN];
bool tag[MAXN];
LL f[MAXN][MAXN];

void init(){
	c[0][0]=1;
	for(int i=1;i<MAXN;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
	}
	fac[0]=1;
	for(int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*i%P;
}

LL getC(int x,int y){
	if(x<y) return 0;
	return c[x][y];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
#endif
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		int i0=0;
		for(int j=1;j<i;j++)
			if(check(a[j],a[i])){
				i0=j;
				break;
			}
		if(!i0){
			tag[i]=1;
			cnt[i]=1;
		}else{
			cnt[i0]++;
		}
	}
	int _n=n;
	n=0;
	s[0]=0;
	for(int i=1;i<=_n;i++)
		if(tag[i]){
			a[++n]=cnt[i];
			s[n]=s[n-1]+a[n];
		}
	f[1][a[1]-1]=1;
	for(int i=2;i<=n;i++){
		int pt=s[i-1]+1;
		for(int j=0;j<=_n;j++)
			if(f[i-1][j]){
				int p1=pt-j,p2=j;
				for(int k=1;k<=a[i];k++){
					LL t1=getC(a[i]-1,k-1);
					for(int l=0;l<=k && l<=p2;l++){
						int j2=p2-l+a[i]-k;
						update(f[i][j2],f[i-1][j]*t1%P*getC(p2,l)%P*getC(p1,k-l));
					}
				}
			}
	}
	LL res=f[n][0];
	for(int i=1;i<=n;i++)
		res=res*fac[a[i]]%P;
	printf("%d\n",res);
	return 0;
}