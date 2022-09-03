#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
vector<int> v[2005];
int c[2005];
int ok=1;
vector<int> dfs(int x){
    vector<int> ret;
    for(auto it:v[x]){
        for(auto it2:dfs(it)){
            ret.pb(it2);
        }
    }
    if(ret.size()<c[x])ok=0;
    vector<int> tmp;
    for(int j=0;j<ret.size();j++){
        if(j==c[x])tmp.pb(x);
        tmp.pb(ret[j]);
    }
    if(c[x]==ret.size())tmp.pb(x);
    return tmp;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d %d",&x,&c[i]);
        v[x].pb(i);
    }
    
    vector<int> res=dfs(v[0][0]);
    if(!ok){
        printf("NO\n");
        return 0;
    }
    int ans[2005];
    for(int i = 0;i<n;i++){
        ans[res[i]]=i+1;
    }
    
    printf("YES\n");
    for(int i = 1;i<=n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}
/*
     0   
     1   1
     2   3
     3 5  1 0 0
    4*/