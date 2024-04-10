/**
 *    author:  gary
 *    created: 25.10.2021 14:32:25
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
const int MAXN=3e5+10;
int n,a[MAXN];
int drop[MAXN];
int dp[MAXN];
int pre[MAXN];
int inde[MAXN];
int main(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    rb(i,1,n){
        int b;
        scanf("%d",&b);
        drop[i]=i+b;
    }
    set<int> unvis;
    rb(i,0,n) unvis.insert(i);
    memset(dp,63,sizeof(dp));
    priority_queue<pair<int,int> ,vector<mp>,greater<mp> > pq;
    dp[n]=0;
    pq.push(II(0,n));
    inde[n]=n;
    while(!pq.empty()){
        auto now=pq.top();
        pq.pop();
        if(now.FIR==dp[now.SEC]){
        }
        else{
            continue;
        }
        int r=now.SEC,l=now.SEC-a[now.SEC];
        auto ite=unvis.lower_bound(l);
        while(ite!=unvis.end()&&*ite<=r){
            if(*ite==0){
                vector<int> ans;
                ans.PB(0);
                int noww=now.SEC;
                while(noww!=n){
                    ans.PB(inde[noww]);
                    noww=pre[noww];
                }
                reverse(ALL(ans));
                printf("%d\n",(int)(ans.size()));
                for(auto it:ans){
                    printf("%d ",it);
                }
                return 0;
            }
            int nex=drop[*ite];
            if(dp[nex]>now.FIR+1){
                pre[nex]=now.SEC;
                inde[nex]=*ite;
                dp[nex]=now.FIR+1;
                pq.push(II(dp[nex],nex));
            }
            ite=unvis.erase(ite);
        }
    }
    cout<<-1<<endl;
    return 0;
}