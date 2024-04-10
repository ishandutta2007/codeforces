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
int n,q;
void solve(){
    cin>>n>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if((x+y)%2){
            if(x%2){
                cout<<(n*n+1)/2+(x-1)*n/2+y/2<<endl;
            }
            else{
                cout<<(n*n+1)/2+(x-2)*n/2+n/2+(y+1)/2<<endl;
            }
        }
        else{
            if(x%2){
                cout<<(x-1)*n/2+(y+1)/2<<endl;
            }
            else{
                cout<<(x-2)*n/2+(n+1)/2+y/2<<endl;
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