#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
int m,d;
#define Maxn 2005
char ch1[Maxn],ch2[Maxn];
int num1[Maxn],l1,num2[Maxn],l2;
bool vis[Maxn][2005][2];
int f[Maxn][2005][2];
int h[Maxn];
int dfs(int *num,int at,int len,int sum,bool limit){
    if(at==len)return sum%m==0;
    if(!limit&&vis[len-at][sum][at&1])return f[len-at][sum][at&1];
    int Ans=0;
    if((at+1)&1){
        int up=(limit?num[at+1]:9);
        for(int i=0;i<=up;++i)
            if(i!=d)Ans=(Ans+dfs(num,at+1,len,(sum*10+i)%m,limit&(i==up)))%Mod;
        if(!limit){
            vis[len-at][sum][at&1]=true;
            f[len-at][sum][at&1]=Ans;
        }
        return Ans;
    }
    int up=(limit?num[at+1]:9);
    if(up>=d)Ans=(Ans+dfs(num,at+1,len,(sum*10+d)%m,limit&(d==up)))%Mod;
    if(!limit){
        vis[len-at][sum][at&1]=true;
        f[len-at][sum][at&1]=Ans;
    }
    return Ans;
}
int main(){
    int len;
    scanf("%d%d",&m,&d);
    scanf("%s",ch1+1);
    len=strlen(ch1+1);l1=len;
    for(int i=1;i<=len;++i)num1[i]=ch1[i]-'0';
    for(int i=len;i>=1;--i){
        num1[i]--;
        if(num1[i]>=0)break;
        num1[i]+=10;
    }
    if(!num1[1]&&l1>1){
        for(register int i=1;i<l1;++i)num1[i]=num1[i+1];
        l1--;
    }
    scanf("%s",ch2+1);
    l2=strlen(ch2+1);
    for(int i=1;i<=l2;++i)num2[i]=ch2[i]-'0';
    int Ans=0;
    int pre=l2;
    for(register int i=1;i<=pre;++i){
        for(register int j=1;j<=(i==1?num2[1]:9);++j)
            if(j!=d)Ans=(Ans+dfs(num2,1,l2,j%m,i==1&&j==num2[1]))%Mod;
        for(register int j=1;j<l2;++j)num2[j]=num2[j+1];
            l2--;
    }
    pre=l1;
    for(register int i=1;i<=pre;++i){
        for(register int j=1;j<=(i==1?num1[1]:9);++j)
            if(j!=d)Ans=(Ans-dfs(num1,1,l1,j%m,i==1&&j==num1[1])+Mod)%Mod;
        for(register int j=1;j<l1;++j)num1[j]=num1[j+1];
        l1--;
    }
    printf("%d\n",Ans);
    return 0;
}