/**
 *    author:  gary
 *    created: 12.08.2022 17:25:16
**/
#include<bits/stdc++.h>
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
const int MAXN=16;
int n,k,a[MAXN];
bitset<2001> dp[1<<MAXN];
priority_queue<mp,vector<mp>,greater<mp> > pq;
vector<mp> ve;
void recover(int mask,int i){
    // cerr<<mask<<' '<<i<<endl;
    if(mask==0) return;
    if(i*k<=2000&&dp[mask][i*k]){
        for(auto &it:ve) it.first++;
        recover(mask,i*k);
        return;
    }
    rep(j,n) if(((mask>>j)&1)&&i>=a[j]&&dp[mask^(1<<j)][i-a[j]]){
        ve.emplace_back(0,a[j]);
        recover(mask^(1<<j),i-a[j]);
        return;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    rep(i,n) cin>>a[i];
    dp[0].set(0);
    rep(mask,1<<n){
        rl(i,2000,1) if(i%k==0&&dp[mask][i]) dp[mask].set(i/k);
        rep(j,n) if(!((mask>>j)&1)) dp[mask|(1<<j)]|=dp[mask]<<a[j];
    }
    if(dp[(1<<n)-1][1]){
        cout<<"YES\n";
        recover((1<<n)-1,1);
        for(auto it:ve) pq.push(it);
        while (pq.size()>1){
            auto A=pq.top();pq.pop();
            auto B=pq.top();pq.pop();
            // cerr<<A.first<<" "<<A.second<<" "<<" "<<B.first<<" "<<B.second<<endl;
            assert(A.first==B.first);
            cout<<A.second<<" "<<B.second<<endl;
            int C_2=A.second+B.second;
            int C_1=A.first;
            while (C_2%k==0){
                C_2/=k;
                C_1++;
            }
            pq.push(II(C_1,C_2));
        }
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}