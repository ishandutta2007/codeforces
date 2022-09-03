#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
set<int> neighbor[100005];
set<int> invneighbor[100005];
map<int,int> v[100005];
int f[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int merge(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(invneighbor[fx].size()>invneighbor[fy].size()){
        swap(fx,fy);
    }
    f[fx]=fy;
    for(auto it:invneighbor[fx]){
        neighbor[it].erase(fx);
        neighbor[it].insert(fy);
        invneighbor[fy].insert(it);
    }
    return fy;
}
int main(){
    int n,m,c,q;
    scanf("%d %d %d %d",&n,&m,&c,&q);
    for(int i = 1;i<=n;i++)
        f[i]=i;
    pii p[100005];
    for(int i = 0;i<m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        p[i]=mp(x,y);
        for(int t = 0;t<2;t++){
            if(v[x].find(z)==v[x].end())
                v[x][z]=y;
            else{
                int fx=Find(v[x][z]);
                int fy=Find(y);
                f[fy]=fx;
            }
            swap(x,y);
        }
    }
    for(int i = 0;i<m;i++){
        neighbor[p[i].x].insert(Find(p[i].y));
        invneighbor[Find(p[i].y)].insert(p[i].x);
        neighbor[p[i].y].insert(Find(p[i].x));
        invneighbor[Find(p[i].x)].insert(p[i].y);
    }
    while(q--){
        char c;
        scanf(" %c",&c);
        if(c=='+'){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            for(int t=0;t<2;t++){
                if(v[x].find(z)==v[x].end())
                    v[x][z]=y;
                else{
                    v[x][z]=merge(v[x][z],y);
                }
                swap(x,y);
            }
            neighbor[x].insert(Find(y));
            invneighbor[Find(y)].insert(x);
            neighbor[y].insert(Find(x));
            invneighbor[Find(x)].insert(y);
        }
        else{
            int x,y;
            scanf("%d %d",&x,&y);
            if(Find(x)==Find(y)){
                printf("Yes\n");
            }
            else{
                if(neighbor[y].find(Find(x))!=neighbor[y].end()){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
        }
    }
}