#include<cstdio>  
#include<iostream>  
#define LL unsigned long long  
#define mod 1000000007
const int LMT=12;  
const int MAN=7;  
using namespace std;  
LL cn[LMT][LMT],zn[LMT][LMT],num[LMT],have[LMT],ans;  
void init(void)  
{  
    zn[0][0]=1;  
    zn[1][0]=cn[1][0]=8;zn[1][1]=cn[1][1]=2;  
    cn[1][0]=7;  
    for(int i=2;i<LMT;i++)  
     for(int j=0;j<=i;j++)  
     {  
         cn[i][j]+=cn[i-1][j]*8;  
         zn[i][j]+=zn[i-1][j]*8;  
         zn[i][j]%=mod;  
         cn[i][j]%=mod;  
         if(j>0)  
         {  
             zn[i][j]+=zn[i-1][j-1]*2;  
             cn[i][j]+=cn[i-1][j-1]*2;  
             zn[i][j]%=mod;  
             cn[i][j]%=mod;  
         }  
     }  
}  
int leng(LL x)  
{  
    int ret=0;  
    do  
    num[ret++]=x%10;  
    while(x/=10);  
    return ret;  
}  
void work(LL x)  
{  
    int end,add=0,nad,len=leng(x);  
    for(int i=len-1;i>0;i--)  
     for(int j=0;j<LMT;j++)  
     {  
         have[j]+=cn[i][j];  
         have[j]%=mod;  
     }  
    for(int i=len-1;i>=0;i--)  
    {  
        if(i==len-1)end=1;  
        else end=0;  
        for(int j=num[i]-1;j>=end;j--)  
        {  
            nad=0;  
            if(j==4||j==7)nad++;  
            for(int t=0;t+nad+add<LMT;t++)  
            {  
                have[t+nad+add]+=zn[i][t];  
                have[t+nad+add]%=mod;  
            }  
        }  
        if(num[i]==4||num[i]==7)add++;  
    }  
    have[add]++;  
}  
void dfs(int pos,LL result,int nhav)  
{  
    if(nhav>=LMT-1)return;  
    if(pos==MAN)  
    {  
        for(int i=nhav+1;i<LMT;i++)  
        {  
            ans+=(result*have[i])%mod;  
            ans%=mod;  
        }  
        return;  
    }  
    for(int i=0;i<LMT;i++)  
    if(have[i])  
    {  
        have[i]--;  
        dfs(pos+1,(result*(have[i]+1))%mod,nhav+i);  
        have[i]++;  
    }  
}  
int main(void)  
{  
    LL m;  
    init();  
    cin>>m;  
    work(m);  
    dfs(1,1,0);  
    ans%=mod;  
    cout<<ans<<endl;  
    return 0;  
}