#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
char s[N];
ll f[N][5],w[N];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        memcpy(f[i],f[i-1],sizeof(f[i]));
        if(s[i]=='h') f[i][1]=min(f[i][1],f[i][0]),f[i][0]=f[i][0]+w[i];
        if(s[i]=='a') f[i][2]=min(f[i][2],f[i][1]),f[i][1]=f[i][1]+w[i];
        if(s[i]=='r') f[i][3]=min(f[i][3],f[i][2]),f[i][2]=f[i][2]+w[i];
        if(s[i]=='d') f[i][4]=min(f[i][4],f[i][3]),f[i][3]=f[i][3]+w[i];
    }
    printf("%lld",min(f[n][0],min(f[n][1],min(f[n][2],f[n][3]))));
    return 0;
}