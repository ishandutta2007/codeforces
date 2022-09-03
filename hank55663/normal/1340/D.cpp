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
#define MAXN 205
#define N 65536
vector<int> v[100005];
set<int> s[100005];
vector<pii> ans;
int Max;
void dfs(int x,int f,int ti,int need){
  //  printf("x:%d need:%d\n",x,need);
    s[x].insert(need-1);
    s[x].insert(ti);
    ans.pb(mp(x,ti));
    int less=v[x].size()-1;
    if(x==1)less++;
    for(auto it:v[x]){
        if(it!=f){
            
           
            if(ti==Max){
                ti=need-less-1;
              //  printf("%d %d %d %d\n",x,ti,need,less);
                s[x].insert(ti);
                ans.pb(mp(x,ti));
             //   now=ti+1;
            }
            dfs(it,x,ti+1,ti+1);
            ans.pb(mp(x,ti+1));
            s[x].insert(ti+1);
            ti=ti+1;
            less--;
        }
    }
    if(ans.back().y!=need-1){
        ans.pb(mp(x,need-1));
    }
//    ans.pb(mp(x,need-1));
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("1\n1 0\n");
        return 0;
    }
    srand(time(NULL));
    for(int i = 1;i<n;i++){
        int x=i+1,y=rand()%i+1;
        scanf("%d %d",&x,&y);
      //  printf("!%d %d\n",x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i = 1;i<=n;i++){
        Max=max(Max,(int)v[i].size());
    }
    dfs(1,0,0,v[1].size()+1);
    for(int i = 1;i<=n;i++)s[i].clear();
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d %d\n",it.x,it.y);
        assert(it.y<=Max);
        assert(s[it.x].find(it.y)==s[it.x].end());
        s[it.x].insert(it.y);
        
    }
}

/*

3 2 +2
3 1 +1
2 1 +1
3 1 +1
2 1 +1

*/
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/