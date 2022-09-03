#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[200005];
int in[200005];
int out[200005];
int p[200005];
int dis[200005];
int t=0;
void dfs(int x,int f){
    p[x]=f;
    in[x]=++t;
    for(auto it:v[x]){
        if(it!=f)
            dfs(it,x);
    }    
    out[x]=t;
}
bool cmp(const int &a,const int &b){
    return in[a]<in[b];
}
vector<pii> tv[200005];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,1);
    while(m--){
        int k;
        scanf("%d",&k);
        vector<int> arr;
        
        for(int i  =0;i<k;i++){
            int x;
            scanf("%d",&x);
            arr.pb(p[x]);
        }
        sort(arr.begin(),arr.end(),cmp);
        int ok=1;
        for(int i = 1;i<arr.size();i++){
            if(in[arr[i]]>out[arr[i-1]])ok=0;
        }
        if(ok){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}