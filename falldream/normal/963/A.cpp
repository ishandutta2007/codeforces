#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<bitset>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long
#define MN 100000
#define mod 1000000009
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char st[MN+5];
int n,a,b,k,ans=0;
inline int pow(int x,int k)
{
    int sum=1;
    for(;k;k>>=1,x=1LL*x*x%mod)
        if(k&1) sum=1LL*sum*x%mod;
    return sum;
}
int main()
{
    n=read();a=read();b=read();k=read();
    scanf("%s",st);
    for(int j=0;j<k;++j) if(j<=n)
    {
        int num=n/k+(n%k>=j),pre=1LL*pow(a,n-j)*pow(b,j)%mod;
        int per=1LL*pow(b,k)*pow(pow(a,k),mod-2)%mod;
        int last=1LL*pre*pow(per,num)%mod;
        //cout<<num<<" "<<pre<<" "<<per<<" "<<last<<endl;
        int now=(per==1)?1LL*num*pre%mod:1LL*(last-pre+mod)*pow((per-1+mod)%mod,mod-2)%mod;
        if(st[j]=='+') ans=(ans+now)%mod;
        else ans=(ans+mod-now)%mod;
    }
    cout<<ans;
    return 0;
}