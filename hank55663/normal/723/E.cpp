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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
set<int> s[205];
int degree[205];
vector<pii> stk;
void dfs(int x){
    if(s[x].size()%2==0)return ;
    stk.pb(mp(x,*s[x].begin()));
    s[*s[x].begin()].erase(x);
    s[x].erase(s[x].begin());
    dfs(stk.back().y);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i = 0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            s[x].insert(y);
            s[y].insert(x);
        }
        int sum=0;
        for(int i = 1;i<=n;i++){
            degree[i]=s[i].size();
            if(degree[i]%2==0)
                sum++;
        }
        for(int i = 1;i<=n;i++){
            if(s[i].size()%2==1){
                stk.pb(mp(i,*s[i].begin()));
                s[*s[i].begin()].erase(i);
                s[i].erase(s[i].begin());
                dfs(stk.back().y);
            }
        }
        for(int i = 1;i<=n;i++){
            if(s[i].size()){
                stk.pb(mp(i,*s[i].begin()));
                s[*s[i].begin()].erase(i);
                s[i].erase(s[i].begin());
                dfs(stk.back().y);
            }
        }
        printf("%d\n",sum);
        for(auto it:stk)
            printf("%d %d\n",it.x,it.y);
        stk.clear();
    }
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */