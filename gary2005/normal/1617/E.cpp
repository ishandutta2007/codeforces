/**
 *    author:  gary
 *    created: 17.12.2021 18:48:31
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
const int MAXN=2e5+1;
int a[MAXN],n;
map<int,int> id;
vector<int> g[MAXN*30];
vector<int> col;
int getpre(int x){
    int len=llround(floor(log2(x-(1e-7))));
    return (1ll<<(len+1))-x;
}
pair<pair<int,mp>,mp> dfs(int now){
    auto answer=II(II(-INF,II(now,now)),II(-INF,now));
    if(col[now]) answer.FIR.FIR=0,answer.SEC.FIR=0;
    for(auto it:g[now]){
        auto tmp=dfs(it);
        check_max(answer.FIR,tmp.FIR);
        tmp.SEC.FIR++;
        auto tmpp=II(answer.SEC.FIR+tmp.SEC.FIR,II(answer.SEC.SEC,tmp.SEC.SEC));
        check_max(answer.FIR,tmpp);
        check_max(answer.SEC,tmp.SEC);
    }
    return answer;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>a[i];
    int cnt=0;
    id[0]=cnt++;
    col.PB(0);
    rb(i,1,n){
        if(id.find(a[i])==id.end()) id[a[i]]=cnt++,col.PB(i);
        else col[id[a[i]]]=i;
        while(a[i]!=0){
            int pr=getpre(a[i]);
            if(id.find(pr)==id.end()) id[pr]=cnt++,col.PB(0);
            g[id[pr]].PB(id[a[i]]);
            a[i]=pr;
        }
    }
    rep(i,cnt){
        sort(ALL(g[i]));
        g[i].erase(unique(ALL(g[i])),g[i].end());
    }
    auto answer=dfs(0);
    if(answer.FIR.FIR==1) cout<<1<<" "<<2<<' '<<1<<endl;
    else
    cout<<col[answer.FIR.SEC.SEC]<<" "<<col[answer.FIR.SEC.FIR]<<' '<<answer.FIR.FIR<<endl;
    return 0;
}