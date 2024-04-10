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
int n;
bool impossible;
set<int> blacklist[33],whitelist[33];
void solve(){
    scanf("%lld\n",&n);
    rep(i,0,n){
        int a,b,c,d=0,x=0;
        char ch;
        char s[11];
        scanf("%c%lld.%lld.%lld.%s\n",&ch,&a,&b,&c,s);
        int l=strlen(s);
        int flag=0;
        rep(j,0,l){
            if(s[j]=='/'){
                flag=1;
                continue;
            }
            if(flag) x=x*10+s[j]-'0';
            else d=d*10+s[j]-'0';
        }
        if(flag==0) x=32;
        int mask=(a<<24)+(b<<16)+(c<<8)+d;
        if(ch=='-') blacklist[x].insert(mask>>(32-x));
        else whitelist[x].insert(mask>>(32-x));
    }
    rep(i,0,33){
        for(auto j:blacklist[i]){
            rep(k,0,i+1){
                if(whitelist[i-k].count(j>>k)){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    rep(i,0,33){
        for(auto j:whitelist[i]){
            rep(k,0,i+1){
                if(blacklist[i-k].count(j>>k)){
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    vii ans;
    for(int i=32;i>=0;i--){
        vi v(all(blacklist[i]));
        for(auto j:v){
            rep(k,0,i){
                if(blacklist[k].count(j>>(i-k))){
                    blacklist[i].erase(j);
                    break;
                }
            }
        }
        vi vv(all(blacklist[i]));
        for(auto j:v){
            if(i and whitelist[i].count(j)==0 and whitelist[i].count(j^1)==0){
                if(blacklist[i].count(j)) blacklist[i].erase(j);
                if(blacklist[i].count(j^1)) blacklist[i].erase(j^1);
                blacklist[i-1].insert(j>>1);
            }
        }
        for(auto j:blacklist[i]){
            ans.pb({j<<(32-i),i});
        }
        for(auto j:whitelist[i]){
            if(i) whitelist[i-1].insert(j>>1);
        }
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans){
        int cur=i.x;
        int d=cur%256;
        cur/=256;
        int c=cur%256;
        cur/=256;
        int b=cur%256;
        cur/=256;
        int a=cur%256;
        cur/=256;
        cout<<a<<"."<<b<<"."<<c<<"."<<d<<"/"<<i.y<<endl;
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