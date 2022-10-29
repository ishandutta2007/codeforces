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

void solve(){
    int n,k;
    cin>>n>>k;
    int d=__builtin_popcount(n);
    if(k<d){
        cout<<"NO"<<endl;
        return;
    }    
    priority_queue<int> pq;
    rep(i,0,32){
        if((n>>i)&1) pq.push(i);
    }
    k-=d;
    while(k){
        auto f=pq.top();
        pq.pop();
        if(!f){
            cout<<"NO"<<endl;
            return;
        }
        pq.push(f-1);
        pq.push(f-1);
        k--;
    }
    cout<<"YES"<<endl;
    while(!pq.empty()){
        int g=pq.top();
        cout<<(1<<g)<<" ";
        pq.pop();
    }
    cout<<endl;
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