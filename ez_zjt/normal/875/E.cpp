#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 300010
#define MAXK 18
using namespace std;

int n;
int a[MAXN];
int fmax[MAXN][MAXK],fmin[MAXN][MAXK],f[MAXN];

void pre_gao(){
	for(int i=n;i>=1;i--){
		fmax[i][0]=fmin[i][0]=a[i];
		for(int j=1;j<MAXK;j++)
			if(i+(1<<(j-1))<=n){
				fmax[i][j]=max(fmax[i][j-1],fmax[i+(1<<(j-1))][j-1]);
				fmin[i][j]=min(fmin[i][j-1],fmin[i+(1<<(j-1))][j-1]);
			}else{
				fmax[i][j]=fmax[i][j-1];
				fmin[i][j]=fmin[i][j-1];
			}
	}
}

int find(int x,int l){
	int maxl=a[x]+l,minl=a[x]-l;
	x++;
	for(int i=MAXK-1;i>=0;i--)
		if(x+(1<<i)-1<=n && fmax[x][i]<=maxl && fmin[x][i]>=minl)
			x+=1<<i;
	return x-1;
}

bool check(int l){
	f[1]=1;
	int lim=find(1,l);
	for(int i=2;i<n;i++)
		if(i<=lim && abs(a[i]-a[i+1])<=l){
			f[i]=1;
			lim=max(lim,find(i,l));
		}else f[i]=0;
	return lim==n;
}

int main(){
#ifdef DEBUG
	freopen("E.in","r",stdin);
#endif
	scanf("%d",&n);
	n+=2;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	pre_gao();
	int l=abs(a[1]-a[2]),r=fmax[1][MAXK-1]-fmin[1][MAXK-1];
	check(459763206);
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}