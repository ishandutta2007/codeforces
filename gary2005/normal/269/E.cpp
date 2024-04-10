/**
 *    author:  gary
 *    created: 17.01.2022 18:54:22
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
void nosolution(){
    cout<<"No solution\n";
    exit(0);
}
int n,m;
int have[7];
vector<mp> g[200005];
vector<vector<mp> > circle,circle2;
bool vis[200005];
vector<mp>path;
void dfs(int now,int pre,int pre2){
    if(vis[now]) return;
    vis[now]=1;
    for(auto it:g[now]) if(it.FIR!=pre||it.SEC-(it.SEC>=INF? INF:0)!=pre2){
        path.PB(II(it.SEC,now));
        dfs(it.FIR,now,it.SEC-(it.SEC>=INF? INF:0));
        break;
    }
}
int maping[200000+5];
int solve(vector<mp> sec){
    int n=sec.size();
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
    if (sec[(i + k) % n].FIR == sec[(j + k) % n].FIR) {
        k++;
    } else {
        sec[(i + k) % n].FIR > sec[(j + k) % n].FIR ? i = i + k + 1 : j = j + k + 1;
        if (i == j) i++;
        k = 0;
    }
    }
    i = min(i, j);
    return i;
}
vector<mp> trans(vector<mp> Tmp){
    int T=solve(Tmp);
    vector<mp> rest;
    rep(i,Tmp.size()) rest.PB(Tmp[(i+T)%Tmp.size()]);
    return rest;
}
bool cmp(vector<mp>& A,vector<mp>& B){
    if(A.size()!=B.size()) return A.size()<B.size();
    rep(i,A.size()) if(A[i].FIR!=B[i].FIR) return A[i].FIR<B[i].FIR;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<int,mp> > line;
    cin>>n>>m;
    rb(i,1,n+m){
        string a,b;
        int c,d;
        cin>>a>>b>>c>>d;
        int ty=-1;
        if(a+b=="LT") ty=1;
        if(a+b=="RT") ty=2;
        if(a+b=="LB") ty=3;
        if(a+b=="RB") ty=4;
        if(a+b=="TB") ty=5;
        if(a+b=="LR") ty=6;
        if(ty==-1){
            swap(a,b);
            swap(c,d);
            if(a+b=="LT") ty=1;
            if(a+b=="RT") ty=2;
            if(a+b=="LB") ty=3;
            if(a+b=="RB") ty=4;
            if(a+b=="TB") ty=5;
            if(a+b=="LR") ty=6;
        }
        line.PB(II(ty,II(c,d)));
        have[ty]++;
    }
    if(have[5]&&have[6]) nosolution();
    if(have[2]!=have[3]||have[1]!=have[4]) nosolution();
    for(auto it:line){
        int u,v;
        tie(u,v)=it.SEC;
        v+=n;
        if(it.FIR>=5){
            if(it.FIR==5){
                u+=n;
                g[u].PB(II(v,INF+it.FIR));
                g[v].PB(II(u,it.FIR));
            }
            else{
                v-=n;
                g[u].PB(II(v,INF+it.FIR));
                g[v].PB(II(u,it.FIR));
            }
        }
        else{
            g[u].PB(II(v,INF+it.FIR));
            g[v].PB(II(u,it.FIR));
        }
    }
    rb(i,1,n+m){
        if(!vis[i]){
            path.clear();
            dfs(i,-1,-1);
            auto path2=path;
            path.clear();
            reverse(ALL(g[i]));
            for(auto it:path2) vis[it.SEC]=0;
            dfs(i,-1,-1);
            path=trans(path);
            path2=trans(path2);
            if(cmp(path,path2));
            else swap(path,path2);
            circle.PB(path);
        }
    }
    line.clear();
    rb(i,1,n+m) g[i].clear();
    rb(i,1,have[1]) line.PB(II(1,II(i,i)));
    rb(i,1,have[2]) line.PB(II(2,II(i,m-i+1)));
    rb(i,1,have[3]) line.PB(II(3,II(n-i+1,i)));
    rb(i,1,have[4]) line.PB(II(4,II(n-i+1,m-i+1)));
    rb(i,1,have[5]) line.PB(II(5,II(have[1]+i,have[3]+i)));
    rb(i,1,have[6]) line.PB(II(6,II(have[1]+i,have[2]+i)));
    for(auto it:line){
        int u,v;
        tie(u,v)=it.SEC;
        v+=n;
        if(it.FIR>=5){
            if(it.FIR==5){
                u+=n;
                g[u].PB(II(v,INF+it.FIR));
                g[v].PB(II(u,it.FIR));
            }
            else{
                v-=n;
                g[u].PB(II(v,INF+it.FIR));
                g[v].PB(II(u,it.FIR));
            }
        }
        else{
            g[u].PB(II(v,INF+it.FIR));
            g[v].PB(II(u,it.FIR));
        }
    }
    memset(vis,0,sizeof(vis));
    rb(i,1,n+m){
        if(!vis[i]){
            path.clear();
            dfs(i,-1,-1);
            auto path2=path;
            path.clear();
            reverse(ALL(g[i]));
            for(auto it:path2) vis[it.SEC]=0;
            dfs(i,-1,-1);
            path=trans(path);
            path2=trans(path2);
            if(cmp(path,path2));
            else swap(path,path2);
            circle2.PB(path);
        }
    }
    sort(ALL(circle),cmp);
    sort(ALL(circle2),cmp);
    if(circle.size()!=circle2.size()) nosolution();
    rep(i,circle.size()){
        if(circle[i].size()!=circle2[i].size()) nosolution();
        rep(j,circle[i].size()) if(circle[i][j].FIR!=circle2[i][j].FIR) nosolution();
        rep(j,circle[i].size()) maping[circle2[i][j].SEC]=circle[i][j].SEC;
    }
    rb(i,1,n+m){
        cout<<maping[i]-(maping[i]>n? n:0)<<" ";
        if(i==n) cout<<endl;
    }
    return 0;
}