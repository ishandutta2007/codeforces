#include<bits/stdc++.h>
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
#define index Index
#define MXN 10000

void solve(){
    int n;
    scanf("%d",&n);
    int p[205];
    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    int vis[205];
    MEM(vis);
    vector<vector<int> > q;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            vector<int> v;  
            int now=i;
            do{
                v.pb(now);
                now=p[now];
                vis[now]=1;
            }while(now!=i);
            q.pb(v);
        }
    }
    int res=0;
    for(int i = 1;i<=n;i++){
        int ok=1;
        while(ok){
            ok=0;
            for(int a=0;a<q.size();a++){
                for(int b=a+1;b<q.size();b++){
                    for(int x=0;x<q[a].size();x++){
                        for(int y=0;y<q[b].size();y++){
                            if(abs(q[a][x]-q[b][y])==i){
                                res+=2*i;
                               vector<int> tmp;
                               for(int j = 0;j<x;j++)tmp.pb(q[a][j]);
                               for(int j=y;j<q[b].size();j++)tmp.pb(q[b][j]);
                               for(int j=0;j<y;j++)tmp.pb(q[b][j]);
                               for(int j =x;j<q[a].size();j++)tmp.pb(q[a][j]); 
                                ok=1;
                                swap(q[b],q.back());
                                q.pop_back();
                                swap(q[a],q.back());
                                q.pop_back();
                                q.pb(tmp);
                            }
                            if(ok)break;
                        }
                        if(ok)break;
                    }
                    if(ok)break;
                }
                if(ok)break;
            }
        }
    }
    reverse(q[0].begin(),q[0].end());
    for(auto it:q[0]){
        printf("%d ",it);
    }
    printf("\n");
    int res2=0;
    for(int j = 0;j<q[0].size();j++){
        res2+=abs(q[0][j]-p[q[0][(j+1)%n]]);
    }
   // printf("%d %d\n",res,res2);
    assert(res==res2);
}

int main(){
   // srand(time(NULL));
    int t=1;;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}