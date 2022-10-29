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
int n,d,x[200005];
priority_queue<int> pq;
void solve(){
    cin>>n>>d;
    rep(i,1,n+1){
        cin>>x[i];
    }
    rep(i,1,n+1){
        int w;
        cin>>w;
        pq.push(w);
    }
    x[d]+=pq.top();
    int pos=d;
    pq.pop();
    for(int i=d-1;i>=1;i--){
        while(!pq.empty() and pq.top()+x[i]>x[d]) pq.pop();
        if(!pq.empty()){
            pq.pop();
            pos--;
        }
        else break;
    }
    cout<<pos<<endl;
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