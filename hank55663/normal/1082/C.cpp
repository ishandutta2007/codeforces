#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL long long 
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define cpdd const pdd
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Line pll
#define EPS 1e-12
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> v[100005];
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].pb(b);
    }
    int ans[100005];
    MEM(ans);
    for(int i=1;i<=m;i++){
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
        for(int j=1;j<v[i].size();j++){
            v[i][j]+=v[i][j-1];
            ans[j]+=max(0,v[i][j]);
        }
        if(v[i].size())
        ans[0]+=max(0,v[i][0]);
    }
    int res=0;
    for(int i=0;i<=n;i++){
        res=max(res,ans[i]);
    }
    printf("%d\n",res);
}