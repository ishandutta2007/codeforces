#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define INF 2000000000
#define ll long long
using namespace std;
inline int read()
{
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9')ch = getchar();
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x;
}

int n,num,s[12313],k;

int main()
{
    n=read();k=read();
    for(int i=2;n>1;i++)
        while(n%i==0) n/=i,s[++num]=i;
    if(num<k)return 0*puts("-1");
    for(int i=k+1;i<=num;i++) s[k]*=s[i];
    for(int i=1;i<=k;i++) cout<<s[i]<<" ";
    return 0;
}