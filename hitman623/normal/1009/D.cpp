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
int phi[100005];
void computeTotient(int n){
    for (int i=2; i<=n; i++)
        phi[i] = i; // indicates not evaluated yet
    for (int p=2; p<=n; p++){
        if (phi[p] == p){
            phi[p] = p-1;
            for (int i = 2*p; i<=n; i += p){
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
    rep(i,1,n+1){
        phi[i]+=phi[i-1];
    }
}
void solve(){
    computeTotient(100003);
    int n,m;
    cin>>n>>m;
    if(m<n-1){
        cout<<"Impossible"<<endl;
        return;
    }
    if(phi[n]>=m){
        cout<<"Possible"<<endl;
        rep(i,1,n+1){
            rep(j,i+1,n+1){
                if(m and __gcd(i,j)==1){
                    cout<<i<<" "<<j<<endl;
                    m--;
                    if(m==0) return;
                }
            }
        }
    }
    else cout<<"Impossible"<<endl;
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