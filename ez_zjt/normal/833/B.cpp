#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 40010
#define MAXM 100
using namespace std;

int n,m,sizew;
int f[MAXM][MAXN],sf[MAXM][MAXN];
int v[MAXN];

namespace Seg{
	struct node{
		int tag,max;
	}a[MAXN<<2];

	void init(){
		memset(a,0,sizeof a);
	}

	void pushdown(int x){
		if(a[x].tag){
			if(x<sizew){
				a[x<<1].tag+=a[x].tag; a[x<<1].max+=a[x].tag;
				a[x<<1|1].tag+=a[x].tag; a[x<<1|1].max+=a[x].tag;
			}
			a[x].tag=0;
		}
	}

	void add(int x,int l,int r,int cl,int cr,int v){
		if(l<=cl && cr<=r){
			a[x].tag+=v;
			a[x].max+=v;
			return;
		}
		pushdown(x);
		int mid=(cl+cr)>>1;
		if(l<=mid) add(x<<1,l,r,cl,mid,v);
		if(r>mid) add(x<<1|1,l,r,mid+1,cr,v);
		a[x].max=max(a[x<<1].max,a[x<<1|1].max);
	}
}

void dp(int l){
	static int last[MAXN];
	memset(last,0,sizeof last);
	Seg::init();
	sf[l][0]=f[l][0];
	for(int i=1;i<=n;i++){
		Seg::add(1,i,i,1,sizew,sf[l-1][i-1]);
		Seg::add(1,last[v[i]]+1,i,1,sizew,1);
		last[v[i]]=i;
		f[l][i]=Seg::a[1].max;
		sf[l][i]=max(sf[l][i-1],f[l][i]);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(sizew=1;sizew<n;sizew<<=1);
	for(int i=1;i<=n;i++) scanf("%d",v+i);
	memset(f,0x88,sizeof f);
	for(int i=1;i<=m;i++) dp(i);
	printf("%d\n",f[m][n]);
	return 0;
}