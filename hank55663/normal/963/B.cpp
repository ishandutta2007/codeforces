#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
vector<int> v[200005];
vector<int> ok[200005][2];
int dfs(int a){
    for(auto it:v[a]){
        ok[a][dfs(it)].pb(it);
    }
    int d=v[a].size()+1;
    if((d-ok[a][0].size())%2==1)
    return 1;
    else
    return 0;
}
void dfs2(int a){
    for(auto it:ok[a][0])
    dfs2(it);
    if(a!=0)
    printf("%d\n",a);
    for(auto it:ok[a][1])
    dfs2(it);
}
int main() {
    int n;
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        v[a].pb(i);
    }
    if(dfs(0)==1)
    printf("NO\n");
    else{
        printf("YES\n");
        dfs2(0);
    }
}