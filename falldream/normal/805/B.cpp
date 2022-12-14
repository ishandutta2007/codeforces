#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

int n;

int main()
{
    n=read();
    for(int i=1;i<=n/4;++i)
        printf("aabb");
    n%=4;
    if(n)printf("a");
    if(n>1) printf("a");
    if(n>2) printf("b");
    return 0;
}