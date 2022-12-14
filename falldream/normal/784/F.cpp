#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#include<ctime>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int a[132123];


int main()
{
    int n=read();time_t start = clock();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    while((double)(clock()-start)/CLOCKS_PER_SEC<1.9);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}