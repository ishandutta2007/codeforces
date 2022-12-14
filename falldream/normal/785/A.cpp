#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
#define INF 2000000000
using namespace std;
inline int read()
{
    int  x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

map<string,int> mp;
int n;
ll ans=0;
string st;

int main()
{
    n=read();mp["Tetrahedron"]=4;
    mp["Cube"]=6;
    mp["Octahedron"]=8;
    mp["Dodecahedron"]=12;
    mp["Icosahedron"]=20;
    for(int i=1;i<=n;i++)
        cin>>st,ans+=mp[st];
    cout<<ans;
    return 0;
}