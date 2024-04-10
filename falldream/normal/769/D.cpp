#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}

int a[20];
int s[10005];
int num[10005];
ll ans=0;
int n,k,cnt=0;

void dfs(int i,int j,int x)
{
    if(i==15){if(j==k)s[++cnt]=x;return;}
    dfs(i+1,j,x);
    dfs(i+1,j+1,x|a[i]);
}

int main()
{
    a[1]=1;for(int i=2;i<=14;i++)a[i]=a[i-1]<<1;
    n=read();k=read();
    dfs(1,0,0);
    for(int i=1;i<=n;i++){int x=read();num[x]++;}
    for(int i=0;i<=10000;i++)if(num[i])
        for(int j=1;j<=cnt;j++)
        {int x=i^s[j];if(x>10000)continue;
          if(k!=0) ans+=1LL*num[i]*num[x];
          else ans+=1LL*num[i]*(num[i]-1);
        }
    cout<<(ans>>1);
    return 0;
}