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
string s[2];
int n;
void solve(){
    cin>>n>>s[0]>>s[1];
    int hor=1;
    int x=0,y=1;
    while(y<n+1){
        if(hor){
            if(s[x][y-1]=='1' or s[x][y-1]=='2') y++;
            else{
                if(x) x--;
                else x++;
                hor=0;                
            }
        }
        else{
            if(s[x][y-1]=='1' or s[x][y-1]=='2'){
                cout<<"NO"<<endl;
                return;
            }
            y++;
            hor=1;
        }
    }
    if(x==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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