/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
using namespace std;
typedef long long LL;
vector<int> v[300005];
vector<int> cnt;
int color[300005];
bool dfs(int x,int col){
    color[x]=col;
    cnt[col]++;
    bool ret=true;
    for(auto it:v[x]){
        if(color[it]==-1){
            ret&=dfs(it,col^1);
        }
        else if(color[it]!=(col^1)){
            return false;
        }
    }
    return ret;
}
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        cnt.clear();
        cnt.resize(2*n+100);
        fill(color,color+n+1,-1);
        int ok=1;
        int st=0;
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!dfs(i,st))ok=0;
                st+=2;
            }
        }
        if(!ok)printf("0\n");
        else{
            LL ans=1;
            for(int i=0;i<st;i+=2){
                LL tot=(f_pow(2,cnt[i])+f_pow(2,cnt[i+1]))%mod;
                ans=ans*tot%mod;
            }
            printf("%lld\n",ans);
        }
    }
}
/*
0 1 0
0 0 1
1 0 1
*/