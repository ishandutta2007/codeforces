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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
vector<int> v[100005];
int Size[100005];
int in[100005];
int dep[100005];
int t;
bool cmp(const int &a,const int &b){
    return dep[a]<dep[b];
}
void dfs(int x){
    dep[x]=0;
    for(auto it:v[x]){
        dfs(it);
        dep[x]=max(dep[it]+1,dep[x]);
    }
    sort(v[x].begin(),v[x].end(),cmp);
}
vector<int> ans;
void dfs2(int x){
    in[++t]=x;
    int last=0;
    for(auto it:v[x]){
        if(last!=0){
            for(int j=0;j<dep[last]+1;j++){
                ans.pb(it);
            }
        }
        last=it;
        dfs2(it);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    dfs(0);
    dfs2(0);
    for(int i = 1;i<=n;i++){
        printf("%d ",in[i]);
    }
    printf("\n");
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d ",it);
    }
    printf("\n");
}
/*
0
10
20
30
40

4+3+3+4+3+2+2+1
13:00
11:

11:24
11:48
12:12
12:36
13:00
13:24
13:48
14:12
14:36
*/