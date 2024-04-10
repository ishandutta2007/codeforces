#include <bits/stdc++.h>

#define int         long long
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
const int N=200005;
int p[N],seg[N<<2];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=p[start];
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=max(seg[node<<1],seg[node<<1|1]);
}
int query(int node,int start,int end,int l,int r){
    if(l<=start && r>=end) return seg[node];
    if(r<start || l>end) return 0;
    int mid=(start+end)>>1;
    int ans1=query(node<<1,start,mid,l,r);
    int ans2=query(node<<1|1,mid+1,end,l,r);
    return max(ans1,ans2);
}
int n,pos[200005],ans;
void go(int l,int r){
	if(l>=r) return;
	int w=query(1,1,n,l,r);
	int q=pos[w];
	go(l,q-1);
	go(q+1,r);
	if(q-l<r-q){
		rep(i,l,q+1){
			int val=w-p[i];
			if(val>=1 and val<=n and pos[val]>=q and pos[val]<=r){
				ans++;
			}
		}
	}
	else{
		rep(i,q,r+1){
			int val=w-p[i];
			if(val>=1 and val<=n and pos[val]<=q and pos[val]>=l){
				ans++;
			}
		}
	}
}
void solve(){
	cin>>n;
	rep(i,1,n+1){
		cin>>p[i];
		pos[p[i]]=i;
	}
	build(1,1,n);
	go(1,n);
	cout<<ans<<endl;
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