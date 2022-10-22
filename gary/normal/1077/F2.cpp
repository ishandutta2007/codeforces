/**
 *    author:  gary
 *    created: 01.10.2021 14:32:00
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
const int MAXN=5e3+1;
int n,k,x,a[MAXN];
LL dp[MAXN][MAXN];
deque<pair<int,LL > > q[MAXN];
int main(){
    scanf("%d%d%d",&n,&k,&x);
    rb(i,1,n) scanf("%d",&a[i]);
    rb(i,1,n) rb(j,0,x) dp[i][j]=-1e18;
    dp[0][0]=0;
    q[0].PB(II(0,0));
    rb(i,1,n){
        // rb(j,0,x){
        //     dp[i][j]=dp[i-1][j];
        // }
        rb(j,0,x){
            while(q[j].size()&&q[j].front().FIR<i-k){
                q[j].pop_front();
            }
            if(q[j].size()&&j!=x){
                check_max(dp[i][j+1],q[j].front().SEC+a[i]);
            }
        }
        rb(j,0,x){
            if(dp[i][j]>=0){
                while(q[j].size()&&q[j].back().SEC<dp[i][j]){
                    q[j].POB();
                }
                q[j].PB(II(i,dp[i][j]));
            }
        }
    }
    while(q[x].size()&&q[x].front().FIR<=n-k){
        q[x].pop_front();
    }
    if(q[x].empty()) cout<<-1<<endl;
    else cout<<q[x].front().SEC<<endl;
    return 0;
}