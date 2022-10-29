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
int n,have[100005][26];
string s[100005];
int go(int pos,int ch){
    if(pos==-1) return 0;
    bool f=1;
    for(auto i:s[pos]) if(i!=s[pos][0]) f=0;
    if(f){
        if(s[pos][0]==ch+'a') return (go(pos-1,ch)+1)*(sz(s[pos])+1)-1;
        else{
            rep(i,0,pos) if(have[i][ch]) return 1;
            return 0;
        }
    }
    else{
        f=0;
        rep(i,0,pos){
            if(have[i][ch]){
                f=1;
                break;
            }
        }
        string temp=s[pos];
        if(f){
            temp+='a'+ch;
            temp+=s[pos];
        }
        int cnt=0,res=0;
        for(auto i:temp){
            if(i=='a'+ch) cnt++;
            else{
                res=max(res,cnt);
                cnt=0;
            }
        }
        res=max(res,cnt);
        return res;
    }
}
void solve(){
    cin>>n;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
        for(auto j:s[i]){
            have[i][j-'a']=1;
        }
    }
    int ans=0;
    rep(i,0,26) ans=max(ans,go(n-1,i));
    cout<<ans<<endl;
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