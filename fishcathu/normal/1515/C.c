#include<stdio.h>
#define ls i<<1
#define rs i<<1|1
int read()
{
    int a=0;
    char c;
    do c=getchar();while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a;
}
void write(int x,char c)
{
    char a[11],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int q[100001],a[100001];
void solve()
{
    int n=read(),s=read();
    for(int i=1;i<=s;++i)
    {
        q[i]=i;
        a[i]=0;
    }
    read();
    puts("YES");
    while(n--)
    {
        int x=q[1],i=1;
        write(x,' ');
        a[x]+=read();
        while(ls<=s)
        {
            int t=ls==s||a[q[ls]]<a[q[rs]]?ls:rs;
            if(a[q[t]]>=a[x])break;
            q[i]=q[t];
            i=t;
        }
        q[i]=x;
    }
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}