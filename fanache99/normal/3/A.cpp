#include<stdio.h>
using namespace std;
char abs(int a){
    if(a>0)
        return a;
    else
        return a*-1;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    char a,b,c,d,l1,l2,i;
    scanf("%c%c\n%c%c",&a,&b,&c,&d);
    a=a-'a'+1;
    c=c-'a'+1;
    b=b-'0';
    d=d-'0';
    l1=abs(a-c);
    l2=abs(b-d);
    if(l2>l1)
        printf("%d\n",l2);
    else
        printf("%d\n",l1);
    if(a<c&&b>=d)
        if(l1>l2){
            for(i=1;i<=l2;i++)
                printf("RD\n");
            for(i=l2+1;i<=l1;i++)
                printf("R\n");
        }
        else{
            for(i=1;i<=l1;i++)
                printf("RD\n");
            for(i=l1+1;i<=l2;i++)
                printf("D\n");
        }
    if(a>=c&&b>=d)
        if(l1>l2){
            for(i=1;i<=l2;i++)
                printf("LD\n");
            for(i=l2+1;i<=l1;i++)
                printf("L\n");
        }
        else{
            for(i=1;i<=l1;i++)
                printf("LD\n");
            for(i=l1+1;i<=l2;i++)
                printf("D\n");
        }
    if(a>=c&&b<d)
        if(l1>l2){
            for(i=1;i<=l2;i++)
                printf("LU\n");
            for(i=l2+1;i<=l1;i++)
                printf("L\n");
        }
        else{
            for(i=1;i<=l1;i++)
                printf("LU\n");
            for(i=l1+1;i<=l2;i++)
                printf("U\n");
        }
    if(a<c&&b<d)
        if(l1>l2){
            for(i=1;i<=l2;i++)
                printf("RU\n");
            for(i=l2+1;i<=l1;i++)
                printf("R\n");
        }
        else{
            for(i=1;i<=l1;i++)
                printf("RU\n");
            for(i=l1+1;i<=l2;i++)
                printf("U\n");
        }
    return 0;
}