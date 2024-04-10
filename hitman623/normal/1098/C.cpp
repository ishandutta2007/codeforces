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
int f(int n,int k,int h,int d){
    int cnt=0,siz=0;
    while(siz+d<=n){
        cnt+=d*h;
        siz+=d;
        d*=k;
        h++;
    }
    return cnt+(n-siz)*h;
}
int n,s,k,freq[100005],nodes,curs;
void solve(){
    cin>>n>>s;
    if(2*s>n*(n+1) or s<2*n-1){
        cout<<"No"<<endl;
        return;
    }
    if(2*s==n*(n+1)){
        cout<<"Yes"<<endl;
        rep(i,2,n+1) cout<<i-1<<" ";
        return;
    }
    rep(i,1,n){
        if(f(n,i,1,1)<=s){
            k=i;
            break;
        }
    }
    freq[1]=1;
    nodes++;
    curs++;
    rep(i,2,n+1){
        if(nodes==n) break;
        int lo=0,hi=min(n-nodes,freq[i-1]*k);
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(curs+f(n-nodes,k,i,mid)<=s) hi=mid;
            else lo=mid;
        }
        int l=hi;
        freq[i]=l;
        nodes+=l;
        curs+=i*l;
    }
    cout<<"Yes"<<endl;
    int node=1;
    rep(i,2,n+1){
        int cur=node;
        rep(j,1,freq[i]+1){
            cout<<cur<<" ";
            if(j%k==0) cur--;
        }
        node+=freq[i];
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