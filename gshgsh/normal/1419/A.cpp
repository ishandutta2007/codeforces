#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int T,N,a[MAXN];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';}
        if(N&1){bool flag=0;For(i,1,N+1>>1)flag|=a[(i<<1)-1]&1;cout<<2-flag<<endl;}
        else{bool flag=0;For(i,1,N>>1)flag|=!(a[i<<1]&1);cout<<flag+1<<endl;}
    }
    return 0;
}