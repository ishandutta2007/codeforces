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
int n,k;
string s;
vii v;
void solve(){
    v.clear();
    cin>>n>>k>>s;
    rep(i,0,n){
        if(i%2 and s[i]=='('){
            int pos=-1;
            rep(j,i+1,n){
                if(j%2==0 and s[j]==')'){
                    pos=j;
                    break;
                }
            }
            v.pb({i+1,pos+1});
            reverse(s.begin()+i,s.begin()+pos+1);
        }
        else if(i%2==0 and s[i]==')'){
            int pos=-1;
            rep(j,i+1,n){
                if(j%2 and s[j]=='('){
                    pos=j;
                    break;
                }
            }
            v.pb({i+1,pos+1});
            reverse(s.begin()+i,s.begin()+pos+1);
        }
    }
    rep(i,0,n/2-k){
        swap(s[2*i+1],s[2*i+2]);
        v.pb({2*i+2,2*i+3});
    }
    cout<<sz(v)<<endl;
    for(auto i:v) cout<<i.x<<" "<<i.y<<endl;
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