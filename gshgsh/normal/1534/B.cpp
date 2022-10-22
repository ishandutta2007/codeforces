#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 500001
int T,N,a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
    T=get();
    while(T--)
    {
        N=get();For(i,1,N)a[i]=get();a[0]=a[N+1]=0;
        ll ans=0;For(i,1,N)if(a[i]>a[i-1]&&a[i]>a[i+1]){int delta=a[i]-max(a[i-1],a[i+1]);ans+=delta,a[i]-=delta;}
        For(i,0,N)ans+=abs(a[i]-a[i+1]);cout<<ans<<endl;
    }
    return 0;
}