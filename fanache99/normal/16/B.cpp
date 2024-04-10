#include <stdio.h>
#include<algorithm>
using namespace std;
struct box{int a,b;};
box v[21];
bool cmp(box a,box b){
    if(a.b>b.b)
        return true;
    else
        return false;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,i;
    long long nr=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d%d",&v[i].a,&v[i].b);
    sort(v+1,v+m+1,cmp);
    for(i=1;i<=m&&n>0;i++)
        if(n>v[i].a){
            n-=v[i].a;
            nr=nr+v[i].a*v[i].b;
        }
        else{
            nr=nr+v[i].b*n;
            n=0;
        }
    printf("%I64d",nr);
    return 0;
}