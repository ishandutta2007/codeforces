#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,tim,entry[500005],ext[500005];
vi a[500005];
void dfs(int node,int par){
	entry[node]=++tim;
	for(auto i:a[node]){
		if(i!=par){
			dfs(i,node);
		}
	}
	ext[node]=tim;
}
const int N=500005;
int seg[2][4*N],lazy[2][4*N];
void update(int node,int start,int end,int l,int r,int val,int f){
    if(lazy[f][node]!=0){
        seg[f][node]=lazy[f][node];
        if(start!=end){
            lazy[f][node<<1]=lazy[f][node];
            lazy[f][node<<1|1]=lazy[f][node];
        }
        lazy[f][node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[f][node]=val;
        if(start!=end){
            lazy[f][node<<1]=val;
            lazy[f][node<<1|1]=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val,f);
    update(node<<1|1,mid+1,end,l,r,val,f);
    seg[f][node]=max(seg[f][node<<1],seg[f][node<<1|1]);
}
int query(int node,int start,int end,int l,int r,int f){
    if(start>end || start>r || end<l) return 0;
    if(lazy[f][node]!=0){
        seg[f][node]=lazy[f][node];
        if(start!=end){
            lazy[f][node<<1]=lazy[f][node];
            lazy[f][node<<1|1]=lazy[f][node];
        }
        lazy[f][node]=0;
    }
    if(start>=l && end<=r) return seg[f][node];
    int mid=(start+end)>>1;
    int q1=query(node<<1,start,mid,l,r,f);
    int q2=query(node<<1|1,mid+1,end,l,r,f);
    return max(q1,q2);
}
void solve(){
	cin>>n;
	rep(i,0,n-1){
		int u,v;
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}
	dfs(1,0);
	cin>>q;
	rep(i,1,q+1){
		int type,v;
		cin>>type>>v;
		if(type==1) update(1,1,n,entry[v],ext[v],i,0);
		else if(type==2) update(1,1,n,entry[v],entry[v],i,1);
		else cout<<(query(1,1,n,entry[v],ext[v],1)>=query(1,1,n,entry[v],entry[v],0)?0:1)<<endl;
	}
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}