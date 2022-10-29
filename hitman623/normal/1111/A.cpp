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
string a,b,w="aeiou";
bool isvowel(char c){
    for(auto i:w) if(c==i) return 1;
        return 0;
}
void solve(){
    cin>>a>>b;
    if(sz(a)!=sz(b)) cout<<"No"<<endl;
    else{
        rep(i,0,sz(a)){
            if(isvowel(a[i])==isvowel(b[i]));
            else{
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
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