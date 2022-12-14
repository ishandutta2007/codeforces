#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
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
int s[15];

int main()
{
    int a=read(),b=read(),c=read(),d=read();
    cout<<(((a^b)&(c|d))^((b&c)|(a^d)));
    return 0;
}