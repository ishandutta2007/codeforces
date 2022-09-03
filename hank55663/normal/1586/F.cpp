#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
int ans[1005][1005];
int Max;
void go(vector<int> v,int k,int d){
    if(v.size()==1||v.empty())return;
    Max=max(Max,d);
    vector<vector<int>> tmp(k,vector<int>());
    for(int i = 0;i<v.size();i++){
        tmp[i%k].pb(1);
    }
    int now=0;
    for(auto &it:tmp){
        for(auto &it2:it)it2=v[now++];
    }
    for(int i = 0;i<k;i++){
        for(int j = i+1;j<k;j++){
            for(auto x:tmp[i]){
                for(auto y:tmp[j]){
                  //  printf("%d %d\n",x,y);
                    ans[x][y]=ans[y][x]=d;
                }
            }
        }
    }
    for(int i = 0;i<k;i++){
        go(tmp[i],k,d+1);
    }
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    for(int i = 1;i<=n;i++){
        v.pb(i);
    }
    go(v,k,1);
    printf("%d\n",Max);
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++)printf("%d ",ans[i][j]);
    }
    printf("\n");
}
int main(){
    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
[[([(([([([
1 8
3 4
1 8
2 7
5 6
*/