/**
 *    author:  gary
 *    created: 21.03.2022 12:30:16
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
const int MAXN=2e5+10;
vector<int> gg[MAXN],gs[MAXN],g[MAXN];
int h[MAXN],need[MAXN],n,mn[MAXN];
vector<int> each[MAXN];
bool tag[MAXN];
void solve(int he){
    deque<mp> dq;
    for(auto it:each[he]) if(need[it]>0) need[it]=0,dq.PB(II(0,it));
    while (!dq.empty())
    {
        auto now=dq.front();
        dq.pop_front();
        if(now.first!=need[now.second]) continue;
        if(now.first==0) mn[now.second]=he;
        for(auto it:gg[now.second]){
            if(need[it]>max(0,now.first-1)){
                need[it]=max(0,now.first-1);
                dq.push_front(II(need[it],it));
            }
        }
        for(auto it:gs[now.second]){
            if(need[it]>now.first+1){
                need[it]=now.first+1;
                dq.push_back(II(need[it],it));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(h,63,sizeof(h));
    cin>>n;
    queue<int> q;
    rb(i,1,n){
        bool li;
        cin>>li;
        if(li) h[i]=0,q.push(i);
    }
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    while (!q.empty()){
        auto now=q.front();
        q.pop();
        for(auto it:g[now]) if(h[it]==INF){
            h[it]=h[now]+1;
            q.push(it);
        }
    }
    rb(i,1,n){
        for(auto it:g[i]){
            if(h[it]>h[i]) gg[i].PB(it);
            if(h[it]==h[i]) gs[i].PB(it);
        }
    }
    memset(need,63,sizeof(need));
    rb(i,1,n) if(gs[i].size()) each[h[i]].PB(i);
    rb(i,1,n) mn[i]=h[i];
    rb(i,0,n){
        solve(i);
    }
    rb(i,1,n){
        // cout<<i<<" "<<h[i]<<' '<<mn[i]<<endl;
        cout<<(h[i]-mn[i])+h[i]<<' ';
    }
    cout<<endl;
    return 0;
}