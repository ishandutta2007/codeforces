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
int n;
string s,t;
vi ans;
void solve(){
    cin>>n>>s>>t;
    string _s=s,_t=t;
    sort(all(_s));
    sort(all(_t));
    if(_s!=_t){
        cout<<-1<<endl;
        return;
    }
    rep(i,0,n){
        rep(j,i,n){
            if(s[j]==t[i]){
                for(int k=j;k>i;k--){
                    ans.pb(k-1);
                    swap(s[k-1],s[k]);
                }
                break;
            }
        }
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans){
        cout<<i+1<<" ";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}