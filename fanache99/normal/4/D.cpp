#include<stdio.h>
#include<algorithm>
using namespace std;
struct plic{int l,h,p;};
plic v[5001];
int L[5001];
bool cmp(plic a,plic b){
    if(a.l<b.l)
        return true;
    else
        if(a.l>b.l)
            return false;
        else
            if(a.h<b.h)
                return true;
            else
                return false;
}
int main(){
    //freopen("4d.in","r",stdin);
    //freopen("4d.out","w",stdout);
    int n,lmin,hmin,i,l,h,nr=0,max,j,maxtot=-1;
    scanf("%d%d%d",&n,&lmin,&hmin);
    v[1].h=hmin;
    v[1].l=lmin;
    nr=1;
    for(i=1;i<=n;i++){
        scanf("%d%d",&l,&h);
        if(l>lmin&&h>hmin){
            nr++;
            v[nr].l=l;
            v[nr].h=h;
            v[nr].p=i;
        }
    }
    sort(v+1,v+nr+1,cmp);
    L[nr]=1;
    if(nr==1)
        printf("0");
    else{
        for(i=nr-1;i>=1;i--){
            max=0;
            for(j=i+1;j<=nr;j++)
                if(v[i].l<v[j].l&&v[i].h<v[j].h&&max<L[j])
                    max=L[j];
            L[i]=max+1;
            if(max+1>maxtot)
                maxtot=max+1;
        }
        maxtot--;
        printf("%d\n",maxtot);
        i=2;

        while(L[i]!=maxtot)
            i++;
        l=v[i].l;
        h=v[i].h;
        printf("%d ",v[i].p);
        maxtot--;
        for(i=i+1;i<=nr;i++)
            if(L[i]==maxtot&&v[i].l>l&&v[i].h>h){
                l=v[i].l;
                h=v[i].h;
                printf("%d ",v[i].p);
                maxtot--;
            }
    }
    return 0;
}