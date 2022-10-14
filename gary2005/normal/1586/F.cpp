/**
 *    author:  gary
 *    created: 17.10.2021 20:22:04
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
int e[1001][1001];
int ne[1001][1001];
int solve(int n,int k){
    if(n<=k){
        rb(i,1,n)
            rb(j,i+1,n)
                e[i][j]=1;
        return 1;
    }
    int ans=solve((n+k-1)/k,k)+1;
    vector<vector<int> > fuck;
    fuck.resize((n+k-1)/k);
    int now=0;
    rb(i,1,fuck.size()){
        rb(j,1,k){
            now++;
            if(now==n+1) break;
            fuck[i-1].PB(now);
        }
    }
    for(auto it:fuck){
        rep(j,it.size())
            rep(i,j){
                ne[it[i]][it[j]]=ans;
            }
    }
    rep(i,fuck.size()){
        rep(j,fuck.size()){
            if(j>i)
            for(auto it:fuck[i])
                for(auto itt:fuck[j])
                    ne[it][itt]=e[i+1][j+1];
        }
    }
    rb(i,1,n) rb(j,i+1,n) e[i][j]=ne[i][j];
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k)<<endl;
    rb(i,1,n)
        rb(j,i+1,n) 
            printf("%d ",e[i][j]);
    return 0;
}