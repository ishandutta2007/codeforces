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
int n,m,k,mx1,mx2;
void solve(){
    cin>>n>>m>>k;
    rep(i,1,n+1){
        int x;
        cin>>x;
        if(x>mx1){
            mx2=mx1;
            mx1=x;
        }
        else mx2=max(mx2,x);
    }
    int w=m/(k+1);
    cout<<w*(mx1*k+mx2)+m%(k+1)*mx1<<endl;
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