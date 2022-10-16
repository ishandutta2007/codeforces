#include<cstdio>
#include<unordered_set>
#include<algorithm>
using namespace std;
unordered_set<int> lin[100010];
unordered_set<int> col[100010];
int x[100010],y[100010];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i,sol=0,x0,y0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        lin[x[i]].insert(y[i]);
        col[y[i]].insert(x[i]);
    }
    for(i=1;i<=n;i++)
        if(lin[x[i]].size()<col[y[i]].size()){
            for(auto& y0: lin[x[i]])
                if(y0>y[i])
                    if(col[y[i]].count(x[i]+y0-y[i])>0&&col[y0].count(x[i]+y0-y[i])>0)
                        sol++;
        }
        else
            for(auto& x0: col[y[i]])
                if(x0>x[i])
                    if(lin[x[i]].count(y[i]+x0-x[i])>0&&lin[x0].count(y[i]+x0-x[i])>0)
                        sol++;
    printf("%d",sol);
    return 0;
}