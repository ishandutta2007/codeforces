#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define INF 1000000000
#define MN 100000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int s[100005];
int from1[100005][5],from2[100005][5];
int f1[100005][5],n,f2[100005][5];
char st[100005];

int main()
{
    scanf("%s",st+1);n=strlen(st+1);
    for(int i=1;i<=n;i++)
        s[i]=(st[i]-'0')%3;
    memset(f1,127,sizeof(f1));memset(f2,127,sizeof(f2));
    for(int i=n;i;i--)
    {
        f1[i][s[i]]=n-i;
        for(int j=0;j<=2;j++)
        {
            int nx=(j+3-s[i])%3;
            if(f1[i+1][nx]<=f1[i][j]){f1[i][j]=f1[i+1][nx];from1[i][j]=MN+(i+1)*10+nx;}
            if(f2[i+1][nx]<=f1[i][j]){f1[i][j]=f2[i+1][nx];from1[i][j]=(i+1)*10+nx;}
            if(f1[i+1][j]+1<=f2[i][j]){f2[i][j]=f1[i+1][j]+1;from2[i][j]=MN+(i+1)*10+j;}
            if(f2[i+1][j]+1<=f2[i][j]){f2[i][j]=f2[i+1][j]+1;from2[i][j]=(i+1)*10+j;}
        }
    }
   // for(int i=1;i<=n;i++)
   //     for(int j=0;j<=2;j++)
   //         cout<<i<<" "<<j<<" "<<f1[i][j]<<" "<<f2[i][j]<<" "<<from1[i][j]<<" "<<from2[i][j]<<endl;
    int ans=INF;int ansfrom;
    for(int i=1;i<=n;i++)if(st[i]!='0')
    {
        if(f1[i][0]+i-1<ans){ans=f1[i][0];ansfrom=MN+i*10;}
      //  if(f2[i][j]+i-1<ans){ans=f2[i][j];ansfrom=n*10+j;}
    }
    for(int i=1;i<=n;i++)if(st[i]=='0')
    {
        if(n-1<ans)return 0*puts("0");
        break;
    }
    if(ans>=INF) return 0*puts("-1");
    for(int i=ansfrom;i;)
    {
        if(i>=MN)cout<<st[i%MN/10],i=from1[i%MN/10][i%10];
        else i=from2[i/10][i%10];
    }
    return 0;
}