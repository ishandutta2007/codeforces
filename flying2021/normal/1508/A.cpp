#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500010
using namespace std;
char s[3][N];
char t[N];
int n;
bool calc(char a[],char b[],char c)
{
    char d=c=='0'?'1':'0';
    int m=0;
    int u=1,v=1;
    while(u<=2*n || v<=2*n)
    {
        while(u<=2*n && v<=2*n && a[u]!=c && b[v]!=c) t[++m]=d,u++,v++;
        while(u<=2*n && a[u]!=c) t[++m]=d,u++;
        while(v<=2*n && b[v]!=c) t[++m]=d,v++;
        if(u<=2*n || v<=2*n) t[++m]=c,u++,v++;
    }
    t[m+1]='\0';
    if(m>n*3) return false;
    printf("%s\n",t+1);
    return true;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        scanf("%d",&n);
        scanf("%s%s%s",s[0]+1,s[1]+1,s[2]+1);
        if(calc(s[0],s[1],'0')) continue;
        if(calc(s[1],s[2],'0')) continue;
        if(calc(s[2],s[0],'0')) continue;
        if(calc(s[0],s[1],'1')) continue;
        if(calc(s[1],s[2],'1')) continue;
        if(calc(s[2],s[0],'1')) continue;
    }
    return 0;
}