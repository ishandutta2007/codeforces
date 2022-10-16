#include<cstdio>
#include<vector>
#define mod 1000000007
using namespace std;
vector<pair<int,int> > v[100010];
int col[100010];
int dfs(int nod,int culoare){
    if(col[nod]>0)
        if(col[nod]==culoare)
            return 1;
        else
            return 0;
    int i,a=v[nod].size(),ok;
    col[nod]=culoare;
    for(i=0;i<a;i++){
        ok=dfs(v[nod][i].first,culoare^v[nod][i].second);
        if(ok==0)
            return 0;
    }
    return 1;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,i,x,y,c,ok,ans=500000004;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&c);
        c=1-c;
        v[x].push_back(make_pair(y,c));
        v[y].push_back(make_pair(x,c));
    }
    for(i=1;i<=n;i++)
        if(col[i]==0){
            ok=dfs(i,2);
            if(ok==1)
                ans=(ans*2)%mod;
            else
                ans=0;
        }
    printf("%d",ans);
    return 0;
}