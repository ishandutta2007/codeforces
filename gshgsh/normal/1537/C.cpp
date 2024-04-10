#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN];int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
    T=get();
    while(T--)
    {
        N=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);int mn=a[2]-a[1],x=1,y=2;For(i,3,N)if(a[i]-a[i-1]<mn)mn=a[i]-a[i-1],x=i-1,y=i;
        if(N==2){cout<<a[1]<<' '<<a[2]<<endl;continue;}For(i,y,N)cout<<a[i]<<' ';For(i,1,x)cout<<a[i]<<" \n"[i==x];
    }
    return 0;
}