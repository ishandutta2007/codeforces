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
int q,l,r;
void solve(){
    cin>>q;
    while(q--){
        cin>>l>>r;
        if(l%2){
            if(r%2){
                cout<<(r-l)/2-r<<endl;
            }
            else{
                cout<<(r-l+1)/2<<endl;
            }
        }
        else{
            if(r%2){
                cout<<-(r-l+1)/2<<endl;
            }
            else{
                cout<<-(r-l+1)/2+r<<endl;
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