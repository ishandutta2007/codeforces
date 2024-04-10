#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
struct prod{char s[101];int nr;};
prod v[101];
int p[101];
char s[101];
bool cmp(prod a,prod b){
    if(a.nr>b.nr)
        return true;
    else
        return false;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,m,i,nr=0,k,pp,a=0,b=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    sort(p+1,p+n+1);
    for(k=1;k<=m;k++){
        scanf("%s",&s);
        pp=0;
        for(i=1;i<=nr&&pp==0;i++)
            if(strcmp(s,v[i].s)==0)
                pp=1;
        if(pp==1)
            v[i-1].nr++;
        else{
            nr++;
            v[nr].nr=1;
            strcpy(v[nr].s,s);
        }
    }
    sort(v+1,v+nr+1,cmp);
    for(i=1;i<=nr;i++){
        a=a+p[i]*v[i].nr;
        b=b+p[n-i+1]*v[i].nr;
    }
    printf("%d %d",a,b);
    return 0;
}