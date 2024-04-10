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
void solve(){
    cin>>n;
    int d=sqrt(n),cur=1;
    while(cur<=n){
        if(cur+d-1<=n){
            rep(j,0,d){
                cout<<cur+d-j-1<<" ";
            }
            cur+=d;
        }
        else{
            int g=cur;
            cur=n;
            while(cur>=g){
                cout<<cur<<" ";
                cur--;
            }
            break;
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