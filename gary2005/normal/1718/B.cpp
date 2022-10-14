/**
 *    author:  gary
 *    created: 19.08.2022 19:50:04
**/
#include<bits/stdc++.h>
#define int LL
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
void solve(){
    int k;
    cin>>k;
    vector<int> c(k);
    LL s=0;
    rep(i,k) cin>>c[i],s+=c[i];
    vector<LL> fib;
    LL sum=0;
    rb(i,1,INF){
        if(sum>=s) break;
        if(fib.size()<2) fib.push_back(1),sum+=1;
        else fib.push_back(fib[fib.size()-2]+fib[fib.size()-1]),sum+=fib.back();
    }
    if(sum!=s){
        cout<<"NO"<<endl;
        return ;
    }
    vector<int> cnt(fib.size());
    vector<int> ano;
    set<int> vis;
    rep(i,fib.size()) if(i&1) vis.insert(fib[i]);
    rep(j,k){
        int x=c[j];
        rl(i,fib.size()-1,0){
            if((i&1)&&fib[i]==x){
                ano.push_back(x);
                x=0;
                break;
            }
            if(x>=fib[i]&&!cnt[i]){
                x-=fib[i];
                cnt[i]++;
                i--;
            }
        }
        if(x){
            cout<<"NO"<<endl;
            return ;
        }
    }
    for(auto it:ano){
        int x=it;
        rl(i,fib.size()-1,0){
            if(x>=fib[i]&&!cnt[i]){
                x-=fib[i];
                cnt[i]++;
                i--;
            }
        }
        if(x){
            cout<<"NO"<<endl;
            return ;
        }
    }
    if(*max_element(ALL(cnt))==1&&*min_element(ALL(cnt))==1){
        cout<<"YES\n";
        return ;
    }
    else{
        cout<<"NO\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}