#include <cstdio>
#include <cstring>
#define MAXN 510
#define P 1000000007
#define LL long long

const int inv[5]={0,1,3,2,4};

int n,m;
int a[MAXN][MAXN];
int highbit[MAXN]={0},b[MAXN]={0};

void gauss(){
	for(int i=1;i<=m;i++){
		int x=0;
		for(int j=1;j<=n;j++)
			if(a[j][i] && !highbit[j]){
				x=j;
				break;
			}
		if(!x) continue;
		highbit[x]=i;
		b[i]=x;
		for(int j=1;j<=n;j++)
			if(a[j][i] && !highbit[j]){
				int temp=inv[a[x][i]]*a[j][i]%5;
				for(int k=i;k<=m;k++)
					a[j][k]=(a[j][k]-temp*a[x][k]%5+5)%5;
			}
	}
}

LL query(){
	static char ask[MAXN];
	scanf("%s",ask+1);
	static int x[MAXN];
	memset(x,-1,sizeof x);
	for(int i=1;i<=m;i++){
		if(!b[i]){
			int temp=0;
			for(int j=1;j<=n;j++)
				temp=(temp+x[j]*a[j][i])%5;
			if(temp!=ask[i]-'a') return 0;
		}else{
			int temp=0;
			for(int j=1;j<=n;j++)
				if(j!=b[i])
					temp=(temp+x[j]*a[j][i])%5;
			x[b[i]]=(ask[i]-'a'-temp+5)*inv[a[b[i]][i]]%5;
		}
	}
	LL res=1;
	for(int i=1;i<=n;i++)
		if(x[i]==-1)
			res=res*5%P;
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		static char str[MAXN];
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
			a[i][j]=str[j]-'a';
	}
	gauss();
	int q;
	scanf("%d",&q);
	while(q--)
		printf("%I64d\n",query());
}