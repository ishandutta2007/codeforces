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
int n,one,two;
vi f[101];
set<int> s1,s2;
string s;
void solve(){
    cin>>n;
    s.resize(n);
    rep(i,0,n){
        int x;
        cin>>x;
        f[x].pb(i);
    }
    rep(i,1,101){
        if(sz(f[i])==1){
            if(sz(s1)<sz(s2)) s1.insert(i),s[f[i][0]]='A';
            else s2.insert(i),s[f[i][0]]='B';
        }
        else if(sz(f[i])==2){
            s[f[i][0]]='A';
            s[f[i][1]]='B';
        }
    }
    rep(i,1,101){
        if(sz(f[i])>2){
            if(sz(s1)>sz(s2)){
                s2.insert(i);
                s[f[i].back()]='B';
                f[i].pop_back();
                while(sz(f[i])){
                    s[f[i].back()]='A';
                    f[i].pop_back();
                }
            }
            else if(sz(s2)>sz(s1)){
                s1.insert(i);
                s[f[i].back()]='A';
                f[i].pop_back();
                while(sz(f[i])){
                    s[f[i].back()]='B';
                    f[i].pop_back();
                }                
            }
            else{
                while(sz(f[i])){
                    s[f[i].back()]='B';
                    f[i].pop_back();
                }                          
            }
        }
    }
    if(sz(s1)!=sz(s2)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<s<<endl;
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