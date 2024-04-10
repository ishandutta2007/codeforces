#include<cstdio>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    for(i=1;i<n;i++)
        if(i%2==1)
            printf("I hate that ");
        else
            printf("I love that ");
    if(n%2==1)
        printf("I hate ");
    else
        printf("I love ");
    printf("it");
    return 0;
}