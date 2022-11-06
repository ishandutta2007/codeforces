#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5010;
const int mo=1e9+7;
const int inf=1e9;
int cnt[N][N],l[N],r[N],c[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%d",&c[i]);
		++r[c[i]];
	}
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		rep(j,y,n)++cnt[x][j];
	}ll ans=0,an=0;
	rep(i,0,n){
		if(i)++l[c[i]],--r[c[i]];
		ll res=0,re=1;
		if(i){
			int t=l[c[i]],p=r[c[i]];
			int lw=cnt[c[i]][t]-cnt[c[i]][t-1];
			if(!lw)continue;
			int rw=cnt[c[i]][p]-(p>=t);
			if(!rw)++res,re=re*lw%mo;
			else res+=2,re=re*lw*rw%mo;
		}
		rep(j,1,n)if(!i||c[i]!=j){
			int mx=l[j],mi=r[j];
			if(mx<mi)swap(mx,mi);
			if(cnt[j][mx]){
				if(!cnt[j][mi])++res,re=re*cnt[j][mx]%mo;
				else if(cnt[j][mx]==1)++res,re=re*2%mo;
				else res+=2,re=re*cnt[j][mi]*(cnt[j][mx]-1)%mo;
			}
		}
		if(res>ans)ans=res,an=re;
		else if(res==ans)an=(an+re)%mo;
	}
	printf("%lld %lld\n",ans,an);
}