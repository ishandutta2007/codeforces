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
int n,sa,sb;
priority_queue<int> a,b;
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        a.push(x);
    }
    rep(i,0,n){
        int x;
        cin>>x;
        b.push(x);
    }    
    int cur=1;
    while(!a.empty() and !b.empty()){
        if(cur%2){
            if(a.top()>b.top()) sa+=a.top(),a.pop();
            else b.pop();
        }
        else{
            if(b.top()>a.top()) sb+=b.top(),b.pop();
            else a.pop();    
        }
        cur++;
    }
    while(!a.empty()){
        if(cur%2){
            sa+=a.top();
        }
        a.pop();
        cur++;
    }
    while(!b.empty()){
        if(cur%2==0){
            sb+=b.top();
        }
        b.pop();
        cur++;
    }
    cout<<sa-sb<<endl;
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