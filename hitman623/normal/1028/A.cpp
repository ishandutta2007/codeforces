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
int n,m,s;
string a[202];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        rep(j,0,m){
            s+=a[i][j]=='B';
        }
    }
    int l=sqrt(s);
    rep(i,0,n){
        rep(j,0,m){
            int f=1;
            rep(k,j,j+l){
                if(a[i][k]!='B'){
                    f=0;
                    break;
                }
            }
            if(f==1){
                cout<<i+l/2+1<<" "<<j+l/2+1<<endl;
                return;
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