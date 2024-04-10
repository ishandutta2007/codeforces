#include<stdio.h>
using namespace std;
int verif(int a,int b,int c){
    if(a+b<c)
        return 0;
    if(b+c<a)
        return 0;
    if(c+a<b)
        return 0;
    if(a+b==c)
        return 1;
    if(b+c==a)
        return 1;
    if(c+a==b)
        return 1;
    return 2;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int a,b,c,d,ppt=0,pps=0,x;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    x=verif(a,b,c);
    if(x==1)
        pps=1;
    if(x==2)
        ppt=1;
    x=verif(a,b,d);
    if(x==1)
        pps=1;
    if(x==2)
        ppt=1;
    x=verif(a,d,c);
    if(x==1)
        pps=1;
    if(x==2)
        ppt=1;
    x=verif(d,b,c);
    if(x==1)
        pps=1;
    if(x==2)
        ppt=1;
    if(ppt==1)
        printf("TRIANGLE");
    else
        if(pps==1)
            printf("SEGMENT");
        else
            printf("IMPOSSIBLE");
    return 0;
}