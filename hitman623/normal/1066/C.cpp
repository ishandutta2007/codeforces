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
int q,curl,curr,lft[200005],rgt[200005];
char g[200005];
void solve(){
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        int id;
        cin>>id;
        if(ch=='L'){
            curl++;
            lft[id]=curl;
            rgt[id]=curl-1;
            g[id]=ch;
        }
        else if(ch=='R'){
            curr++;
            lft[id]=curr-1;
            rgt[id]=curr;
            g[id]=ch;
        }
        else{
            if(g[id]=='L'){
                cout<<min(curl-lft[id],curr+rgt[id])<<endl;
            }
            else{
                cout<<min(curl+lft[id],curr-rgt[id])<<endl;
            }
        }
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