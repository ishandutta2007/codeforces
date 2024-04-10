/**
 *    author:  gary
 *    created: 25.10.2021 13:51:33
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
const int MAXN=1e6+1;
const int B=8191;
int n,a[MAXN];
vector<mp> q[MAXN];
int eachq[B+1];
queue<int> app[5005];
int dp[5005][B+1];
bool vis[B+1];
int main(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]),app[a[i]].push(i);
    rb(i,0,5000) app[i].push(INF);
    rb(i,0,5000) rb(j,0,B) eachq[i^j]=i;
    memset(dp,63,sizeof(dp));
    int cnt=0;
    rb(i,0,5000){
        dp[i][i]=app[i].front();
        if(dp[i][i]!=INF){
            q[dp[i][i]].push_back(II(i,i));
            cnt+=1;
            vis[i]=1;
        }
    }
    rb(t,1,n){
        for(auto it:q[t]){
            while(eachq[it.SEC]!=-1&&eachq[it.SEC]>it.FIR){
                int Tmp_=eachq[it.SEC]--;
                auto Tmp=II(Tmp_,it.SEC^Tmp_);
                while(app[Tmp.FIR].front()<=t) app[Tmp.FIR].pop();
                if(app[Tmp.FIR].front()!=INF){
                    cnt+=vis[Tmp.SEC]==0;
                    vis[Tmp.SEC]=1;
                    if(cnt==B+1) break;
                    dp[Tmp.FIR][Tmp.SEC]=app[Tmp.FIR].front();
                    q[dp[Tmp.FIR][Tmp.SEC]].PB(Tmp);
                }
            }
        }
    }
    vector<int> ans;
    ans.PB(0);
    rb(i,1,B){
        if(vis[i])
            ans.PB(i);
    }
    printf("%d\n",int(ans.size()));
    for(auto it:ans) printf("%d ",it);
    return 0;
}