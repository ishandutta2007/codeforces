#include<bits/stdc++.h>
#define MN 5000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s[MN+5];
int n,f[MN+5][MN+5],lst[MN+5][26];
int main()
{
    n=read();scanf("%s",s+1);
    for(int i=1;i<=n;++i) memcpy(lst[i],lst[i-1],sizeof(lst[0])),lst[i][s[i]-'a']=i;
    for(int i=1;i<=n;++i) f[0][i]=1;
    for(int i=1;i<=n;++i) 
    {
        for(int j=1;j<=n;++j)
            f[i][j]=(f[i-1][j]-f[i-1][lst[j-1][s[j]-'a']]+mod)%mod;
        for(int j=1;j<=n;++j) f[i][j]=(f[i][j]+f[i][j-1])%mod;
    }
    printf("%d\n",f[n][n]);
    return 0;
}