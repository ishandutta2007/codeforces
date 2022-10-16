#include<stdio.h>
using namespace std;
int v[101];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i,min=1000,min2=1000;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&v[i]);
        if(v[i]<min)
            min=v[i];
    }
    for(i=1;i<=n;i++)
        if(v[i]>min&&v[i]<min2)
            min2=v[i];
    if(min2!=1000)
        printf("%d",min2);
    else
        printf("NO");
    return 0;
}