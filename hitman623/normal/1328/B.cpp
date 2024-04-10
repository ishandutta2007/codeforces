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

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    rep(i,0,n) s+='a';
    rep(i,1,n+1){
        if((n-i)*(n-i-1)/2>=k);
        else{
            k-=(n-i)*(n-i-1)/2;
            s[i-1]='b';
            rep(j,i+1,n+1){
                if((n-j)>=k);
                else{
                    s[j-1]='b';
                    cout<<s<<endl;
                    return;
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}