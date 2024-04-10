#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,k,ans;vector<int>wr;
int a[N],l[N],r[N],pp[N],tt[N],mx[N],mi[N],v[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m){
		scanf("%d%d",&l[i],&r[i]);++r[i];
		pp[i]=l[i];pp[i+m]=r[i];
	}
	pp[0]=1;pp[m*2+1]=n+1;
	sort(pp,pp+m*2+2);k=unique(pp,pp+m*2+2)-pp-1;
	rep(i,0,k-1){tt[pp[i]]=i;mx[i]=-inf;mi[i]=inf;
		rep(j,pp[i],pp[i+1]-1)mx[i]=max(mx[i],a[j]),mi[i]=min(mi[i],a[j]);
	}tt[pp[k]]=k;
	rep(i,1,m)l[i]=tt[l[i]],r[i]=tt[r[i]];
	rep(i,0,k-1){
		rep(j,0,k)v[j]=0;
		vector<int>ww;ww.clear();
		rep(j,1,m)if(l[j]<=i&&r[j]>i){
			++v[l[j]],--v[r[j]],ww.pb(j);
		}
		int nw=mx[0]-v[0];
		rep(j,1,k-1)v[j]+=v[j-1],nw=max(nw,mx[j]-v[j]);
		nw-=mi[i]-v[i];
		if(nw>ans)ans=nw,wr=ww;
	}
	printf("%d\n",ans);
	cout<<wr.size()<<'\n';
	for(auto i:wr)printf("%d ",i);
}