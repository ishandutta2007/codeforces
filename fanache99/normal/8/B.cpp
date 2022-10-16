#include<stdio.h>
using namespace std;
int a[204][204],b[204][204];
struct coadda{int l,c;};
coadda coada[1000001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int l=101,c=101,lin[4]={-1,0,1,0},col[4]={0,1,0,-1},ic,sf,k,nr=0,i,j;
    char cc;
    a[l][c]=1;
    while(scanf("%c",&cc)!=EOF)
        if(cc=='R'||cc=='L'||cc=='U'||cc=='D'){
            if(cc=='R')
                c++;
            if(cc=='L')
                c--;
            if(cc=='U')
                l--;
            if(cc=='D')
                l++;
            a[l][c]=1;
            nr++;
        }
    i=l;
    j=c;
    ic=sf=1;
    coada[1].l=coada[1].c=101;
    b[101][101]=1;
    while(ic<=sf){
        for(k=0;k<4;k++){
            l=coada[ic].l+lin[k];
            c=coada[ic].c+col[k];
            if(a[l][c]==1&&b[l][c]==0){
                b[l][c]=b[coada[ic].l][coada[ic].c]+1;
                sf++;
                coada[sf].l=l;
                coada[sf].c=c;
            }
        }
        ic++;
    }
    if(b[i][j]-1<nr)
        printf("BUG");
    else
        printf("OK");
    return 0;
}