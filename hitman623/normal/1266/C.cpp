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
int r,c,cnt,a[505][505];
void solve(){
    cin>>r>>c;
    if(r==1 and c==1){
        cout<<0<<endl;
        return;
    }
    if(r==1){
        rep(i,2,c+2) cout<<i<<" ";
        cout<<endl;
        return;
    }
    if(c==1){
        rep(i,2,r+2) cout<<i<<endl;
        return;
    }
    rep(i,0,r){
        rep(j,0,c){
            a[i][j]=1;
        }
    }
    cnt=1;
    rep(i,0,r){
        rep(j,0,c){
            a[i][j]*=cnt;
        }
        cnt++;
    }
    rep(j,0,c){
        rep(i,0,r){
            a[i][j]*=cnt;
        }
        cnt++;
    }
    set<int> st;
    rep(i,0,r){
        int g=0;
        rep(j,0,c){
            g=__gcd(g,a[i][j]);
        }
        st.insert(g);
    }
    rep(j,0,c){
        int g=0;
        rep(i,0,r){
            g=__gcd(g,a[i][j]);
        }
        st.insert(g);
    }
    if(sz(st)==r+c){
        rep(i,0,r){
            rep(j,0,c){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }        
    }
    else cout<<0<<endl;
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