#include<stdio.h>
using namespace std;
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int a,b,max;
    scanf("%d%d",&a,&b);
    if(a>b)
        max=a;
    else
        max=b;
    if(max==6)
        printf("1/6");
    if(max==5)
        printf("1/3");
    if(max==4)
        printf("1/2");
    if(max==3)
        printf("2/3");
    if(max==2)
        printf("5/6");
    if(max==1)
        printf("1/1");
    return 0;
}