#include<stdio.h>
#include<algorithm>
using namespace std;
int v[10001];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,nr=2,j,k,t=1,i;
    scanf("%d",&n);
    v[1]=0;
    v[2]=1;
    for(i=1;i<=9;i++){
        k=0;
        t*=10;
        for(j=1;j<=nr;j++){
            k++;
            v[nr+k]=t+v[j];
        }
        nr+=k;
    }
    sort(v+1,v+nr+1);
    i=1;
    while(n>=v[i])
        i++;
    i-=2;
    printf("%d",i);
    return 0;
}