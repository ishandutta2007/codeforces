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
int a,b,x;
string s;
void solve(){
    int f=0;
    cin>>a>>b>>x;
    while(x>1 and a and b){
        if(!f) x--;
        else x-=2;
        f=1;
        a--,b--;
        s+="01";
    }
    if(x==0){
        while(b--){
            s+='1';
        }
        reverse(all(s));
        while(a--){
            s+='0';
        }
    }
    else{
        if(a){
            while(b--){
                s+='1';
            }
            while(a--){
                s+='0';
            }
        }
        else if(b){
            reverse(all(s));
            while(a--){
                s+='0';
            }
            while(b--){
                s+='1';
            }
        }
    }
    cout<<s<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}