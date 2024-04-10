#include<bits/stdc++.h>
#define maxn 1000005
#define m 1023

using namespace std;

int n,x,y,k,ans,a,b,c;
char s[5];

int main()
{
    scanf("%d",&n);
    x=0;y=m;
    while (n--)
    {
        scanf("%s",s);
        scanf("%d",&k);
        if (s[0]=='|') x|=k,y|=k;
        if (s[0]=='^') x^=k,y^=k;
        if (s[0]=='&') x&=k,y&=k;
    }
    a=x&y;b=m-((m-x)&(m-y));c=(m-y)&x;
    ans=(a>0)+(b<m)+(c>0);
    printf("%d\n",ans);
    if (a>0) printf("| %d\n",a);
    if (b<m) printf("& %d\n",b);
    if (c>0) printf("^ %d\n",c);
    return 0;
}