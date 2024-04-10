#include<iostream>  
#include<cstring>  
#include<queue>  
#include<cstdio>  
#include<algorithm>  
#define N 210005  
#define inf 100000000  
#define MOD 100000007  
#define LL long long  
#define mem(a,b) memset(a,b,sizeof(a))  
#define Key_value ch[ch[root][1]][0]  
#define _match(a,b) ((a)==(b))  
//#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
int a[40][40],b[40],p[40],k[40];  
int n,u,t;  
LL ans;  
void dfs(int dep,int two){  
    LL tmp=0;  
    for(int i=0;i<n;i++) tmp+=(LL)a[dep][i]*k[i];  
    if((u-dep)%2==0)ans=max(ans,tmp);  
    if(dep==u) return;  
    for(int i=0;i<n;i++) a[dep+1][i]=a[dep][p[i]]+t;  
    dfs(dep+1,0);  
    if(two==1) return;  
    for(int i=0;i<n;i++) a[dep+1][i]=(a[dep][i]^b[i]);  
    dfs(dep+1,1);  
}  
int main(){  
    while(scanf("%d%d%d",&n,&u,&t)!=EOF){  
        for(int i=0;i<n;i++)scanf("%d",&a[0][i]);  
        for(int i=0;i<n;i++)scanf("%d",&b[i]);  
        for(int i=0;i<n;i++)scanf("%d",&k[i]);  
        for(int i=0;i<n;i++)scanf("%d",&p[i]),p[i]--;  
        ans=-(1ll<<60);  
        dfs(0,0);  
        printf("%I64d\n",ans);  
    }  
    return 0;  
}