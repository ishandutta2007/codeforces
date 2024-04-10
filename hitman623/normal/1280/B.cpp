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
int n,m,r[66],c[66],a,b;
string s[66];
void solve(){
    a=b=0;
    memset(r,0,sizeof r);
    memset(c,0,sizeof c);
    cin>>n>>m;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='A'){
                a++;
                r[i]++;
                c[j]++;
            }
            else b++;
        }
    }
    if(a==n*m){
        cout<<0<<endl;
        return;
    }
    if(b==n*m){
        cout<<"MORTAL"<<endl;
        return;
    }
    if(r[0]==m or r[n-1]==m or c[0]==n or c[m-1]==n){
        cout<<1<<endl;
        return;
    }
    int w=0;
    if(s[0][0]=='A' or s[0][m-1]=='A' or s[n-1][0]=='A' or s[n-1][m-1]=='A') w=1;
    rep(i,0,n) if(r[i]==m) w=1;
    rep(i,0,m) if(c[i]==n) w=1;
    if(w){
        cout<<2<<endl;
        return;
    }
    if(r[0]+r[n-1]+c[0]+c[m-1]==0) cout<<4<<endl;
    else cout<<3<<endl;
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