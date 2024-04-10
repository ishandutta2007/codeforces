#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=1e9+7;
const int inf=1e9;
struct pr{
	int l,r;
	friend operator <(const pr&a,const pr&b){return a.l<b.l;}
}a[N];
struct po{
	int x,id,ty;
	friend operator <(const po&a,const po&b){
		return a.x==b.x?a.ty<b.ty:a.x<b.x;
	}
}p[N*2];
ll f[2][N];int sg[2][N],pt[8];
int main(){int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n){
		scanf("%d%d",&a[i].l,&a[i].r);
		++a[i].r;
		p[i*2-1]={a[i].l,i,1};
		p[i*2]={a[i].r,i,0};
	}
	sort(a+1,a+n+1);sort(p+1,p+n*2+1);
	int t=0,lsk=0,nwk=0;
	rep(i,1,n*2){
		t^=1;lsk=nwk;nwk=0;
		rep(j,0,lsk-1)if(p[i].ty||sg[t^1][j]!=p[i].id){
			sg[t][nwk]=sg[t^1][j];
			pt[j]=nwk++;
		}else pt[j]=-1;
		if(p[i].ty)sg[t][nwk++]=p[i].id;
		rep(j,0,(1<<nwk)-1)f[t][j]=0;
		rep(j,0,(1<<lsk)-1){
			ll w=f[t^1][j];int ct=0,x=0;
			rep(l,0,lsk-1)if((j>>l)&1){ct^=1;
				if(~pt[l])x^=1<<pt[l];
			}
			if(ct)w+=p[i].x-p[i-1].x;
			f[t][x]=max(f[t][x],w);
			if(p[i].ty){
				x^=1<<(nwk-1);
				f[t][x]=max(f[t][x],w);
			}
		}
	}
	printf("%lld\n",f[t][0]);
}