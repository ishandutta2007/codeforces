#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<cmath>
#define ll long long
#define INF 2000000000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n;
char s[200005];
ll p[200005],l[200005];
int num1=0,num2=0;
ll ans=0;

ll work(int n,int c)
{
    return p[n]*l[c]%mod*l[n-c]%mod;
}

int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    p[0]=l[0]=l[1]=1;
    for(int i=1;i<=200000;i++)p[i]=p[i-1]*i%mod;
    for(int i=2;i<=200000;i++)l[i]=(mod-mod/i)*l[mod%i]%mod;
    for(int i=2;i<=200000;i++)l[i]=l[i]*l[i-1]%mod;
    for(int i=1;i<=n;i++)num2+=(s[i]==')');
    for(int i=1;i<=n;i++)
    {
        if(s[i]==')')num2--;
        else
        {num1++;ans=(ans+work(num1+num2-1,num2-1))%mod;}
    }
    cout<<ans;
    return 0;
}