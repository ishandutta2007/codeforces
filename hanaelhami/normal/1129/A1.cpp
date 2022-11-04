#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<r;i++)
#define put(x) cout<<#x<<" = "<<x<<endl;
#define X first
#define Y second
#define pb push_back
using namespace std;
typedef long long num;
const int maxn=1e5+10,inf=1e9+10;

int n,m,ans,mnn[maxn];

vector<int> v[maxn];

inline int dis(int i,int j){
    return (j-i+n)%n;
}

int32_t main(){
    cin>>n>>m;
    rep(i,0,n){
	mnn[i]=inf;
    }
    rep(i,0,m){
	int a,b;
	cin>>a>>b;
	a--,b--;
	mnn[a]=min(mnn[a],dis(a,b));
	v[a].pb(dis(a,b));
    }
    rep(i,0,n){
	ans=0;
	int mx=0;
	rep(j,0,n){
	    mx=max(mx,int(v[j].size()));
	}
	rep(j,0,n){
	    if(v[j].size()==0) continue;
	    int res=(int(v[j].size())-1)*n+dis(i,j),rs=inf;
	    //if(mx==int(v[j].size())){
	    rs=min(rs,res+mnn[j]);
	    /*for(int x:v[j]){
	      rs=min(rs,res+x);
	     }*/
	    ans=max(ans,rs);
	    //}
	}
	cout<<ans<<endl;
    }
}