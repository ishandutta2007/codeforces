#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
char s[N],t[N];
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int n=a+b;
    if(c==0)
    {
        puts("Yes");
        for(int i=1;i<=b;i++) putchar('1');
        for(int i=1;i<=a;i++) putchar('0');puts("");
        for(int i=1;i<=b;i++) putchar('1');
        for(int i=1;i<=a;i++) putchar('0');puts("");
        return 0;
    }
    if(a==0 || b==1){puts("No");return 0;}
    for(int i=1;i<=n;i++) s[i]=t[i]='0';
    if(a<c)
    {
        int d=c-a;
        b-=d;
        if(b<=1){puts("No");return 0;}
        for(int i=1;i<=b-1;i++) s[i]=t[i]='1';
        s[b]='1';t[n]='1';
        for(int i=b+1;i<=b+d;i++) s[i]=t[i]='1';
        printf("Yes\n%s\n%s\n",s+1,t+1);
        return 0;
    }
    s[n-c]=t[n]='1';
    int d=b-c;
    for(int i=1;i<=b-1;i++) s[i]=t[i]='1';
    for(int i=b;i<n-c;i++) s[i]=t[i]='0';
    printf("Yes\n%s\n%s\n",s+1,t+1);
    return 0;
}