#include <stdio.h>
#include<algorithm>
using namespace std;
struct casa{int a,x;};
casa v[1001];
int vc[20001];
bool cmp(casa a,casa b){
    if(a.x<b.x)
        return true;
    else
        return false;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,t,pp,nr=0,i,j;
    scanf("%d%d",&n,&t);
    for(i=1;i<=n;i++){
        scanf("%d%d",&v[i].x,&v[i].a);
        v[i].x+=5001;
        v[i].x*=2;
    }
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=n;i++)
        for(j=v[i].x-v[i].a;j<=v[i].x+v[i].a;j++)
            vc[j]=1;
    for(i=1;i<=n;i++){
        pp=0;
        for(j=v[i].x-v[i].a-1;j>=v[i].x-v[i].a-2*t+1&&pp==0;j--)
            if(vc[j]!=0)
                pp=1;
        if(pp==0&&vc[j]==0)
            nr++;
        pp=0;
        for(j=v[i].x+v[i].a+1;j<=v[i].x+v[i].a-1+2*t&&pp==0;j++)
            if(vc[j]!=0)
                pp=1;
        if(pp==0)
            nr++;
    }
    printf("%d",nr);
    return 0;
}