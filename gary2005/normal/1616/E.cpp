/**
 *    author:  gary
 *    created: 31.12.2021 21:05:37
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;

set<int> pos[26];
int n;
string s,t;
bool e[100000+10];
int bit[100000+10];
void era(int pos){
    pos++;
    while(pos<=n){
        bit[pos]--;
        pos+=pos&-pos;
    }
}
void add(int pos){
    pos++;
    while(pos<=n){
        bit[pos]++;
        pos+=pos&-pos;
    }
}
int sum(int pos){
    pos++;
    int s=0;
    while(pos){
        s+=bit[pos];
        pos-=pos&-pos;
    }
    return s;
}
LL solve(int x,int y){
    if(max(x,y)>=n) return INF;
    if(e[x]) return solve(x+1,y);
    LL ans=1e18;
    rb(i,0,t[y]-'a'-1){
        if(!pos[i].empty()){
            check_min(ans,(LL)(sum(*pos[i].begin())-sum(x)));
        }
    }
    if(pos[t[y]-'a'].size()){
        int z=*pos[t[y]-'a'].begin();
        int d=sum(*pos[t[y]-'a'].begin())-sum(x);
        era(z);
        e[z]=1;
        pos[t[y]-'a'].erase(pos[t[y]-'a'].begin());
        check_min(ans,solve(x,y+1)+d);
    }
    return ans;
}
void solve(){

    cin>>n;
    cin>>s>>t;
    rep(i,n) e[i]=0,bit[i+1]=0;
    rb(i,1,n) add(i-1);
    string cp=s;
    sort(ALL(cp));
    
    if(cp>=t){
        cout<<"-1"<<endl;
        return;
    }
    
    rep(i,26) pos[i].clear();

    rep(i,s.length()) pos[s[i]-'a'].insert(i);

    LL answer=solve(0,0);

    cout<<answer<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}