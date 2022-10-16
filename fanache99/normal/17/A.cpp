#include <stdio.h>
using namespace std;
char ciur[1001];
int v[1001],nr=0;
void ciurr(int nrmax){
    int m,prim=2;
    while(prim*prim<=nrmax){
        for(m=2;m<=nrmax/prim;m++)
            ciur[m*prim]=1;
        prim++;
        while(ciur[prim]==1)
            prim++;
    }
    for(m=2;m<=1001;m++)
        if(ciur[m]==0){
            nr++;
            v[nr]=m;
        }
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,k,r=0,i;
    scanf("%d%d",&n,&k);
    ciurr(1001);
    i=1;
    while(v[i]+v[i+1]+1<=n){
        if(ciur[v[i]+v[i+1]+1]==0)
            r++;
        i++;
    }
    if(r>=k)
        printf("YES");
    else
        printf("NO");
    return 0;
}