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
int n,q,a[200005],b[200005],minpos[200005],maxpos[200005],f[200005];
const int N=200005;
int t[2*N];
void build(){
    for(int i=n-1;i>0;--i) t[i]=min(t[i<<1],t[i<<1|1]);
}
int query(int l,int r){
    int res=hell;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=min(res,t[l++]);
        if(r&1) res=min(res,t[--r]);
    }
    return res;
}
void solve(){
    cin>>n>>q;
    int z=0,flag=0;
    rep(i,0,n){
    	cin>>a[i];
    	if(a[i]==q) flag=1;
    	if(a[i]==0) z++;
    }
    if(z==n){
    	cout<<"YES"<<endl;
    	rep(i,0,n) cout<<q<<" ";
    	cout<<endl;
    	return;
    }
    memset(minpos,1,sizeof minpos);
    memset(maxpos,0,sizeof maxpos);
    int d=0;
    for(int i=n-1;i>=0;i--) if(a[i]) d=a[i];
    rep(i,0,n){
    	b[i]=a[i];
    	if(b[i]==0){
    		if(flag==0){
    			b[i]=q;
    			flag=1;
    		}
    		else if(i) b[i]=b[i-1];
    		else b[i]=d;
    	}
    	minpos[b[i]]=min(minpos[b[i]],i);
    	maxpos[b[i]]=max(maxpos[b[i]],i);
    	t[i+n]=b[i];
    	f[b[i]]=1;
    }
    if(f[q]==0){
    	cout<<"NO"<<endl;
    	return;
    }
    build();
    for(int i=q;i>0;i--){
    	if(f[i]==0) continue;
    	if(query(minpos[i],maxpos[i])<i){
    		cout<<"NO"<<endl;
    		return;
    	}
    }
    cout<<"YES"<<endl;
    rep(i,0,n) cout<<b[i]<<" ";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}