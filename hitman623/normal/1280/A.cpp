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
int n,x;
string s;
void solve(){
    cin>>x>>s;
    int cnt=sz(s);
    rep(i,0,x){
        int len=cnt;
        int d=sz(s);
        int m=s[i]-'0';
        rep(_,0,m-1){
            cnt+=(len-i-1+hell)%hell;
            cnt%=hell;
            rep(j,i+1,d){
                if(sz(s)>x) break;
                s+=s[j];
            }
        }
    }
    cout<<cnt<<endl;
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