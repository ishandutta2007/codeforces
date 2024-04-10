#include<cstdio>
int main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(((b*d*f>a*c*e)||(c==0&&d)||(a==0&&b&&d))&&d) printf("Ron");
    else printf("Hermione");
}