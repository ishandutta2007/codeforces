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
vector<int> v[1005];
int label[1005];
int dfs(int x,int f){
    if(label[x])
    return x;
    int ret=-1;
    for(auto it:v[x]){
        if(it!=f){
            ret=dfs(it,x);
            if(ret!=-1)
            return ret;
        }
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        MEM(label);
        for(int i=1;i<=n;i++)
        v[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        int k;
        scanf("%d",&k);
        while(k--){
            int x;
            scanf("%d",&x);
            label[x]=1;
        }
        scanf("%d",&k);
        set<int> s;
        while(k--){
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        printf("B %d\n",*s.begin());
        fflush(stdout);
        int x;
        scanf("%d",&x);
        int ans=dfs(x,0);
        printf("A %d\n",ans);
        fflush(stdout);
        scanf("%d",&x);
        if(s.find(x)!=s.end())
        printf("C %d\n",ans);
        else
        printf("C -1\n");
        fflush(stdout);
    }
}