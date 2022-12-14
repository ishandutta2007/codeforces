#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 200000
#define N 262144
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<int> v[MN+5];
int mx=0,n,a[MN+5];

int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i)
    {
        if(!mx) v[++mx].push_back(a[i]);
        else
        {
            int l=1,r=mx,mid,res=-1;
            while(l<=r)
            {
                mid=l+r>>1;
                if(v[mid][v[mid].size()-1]<a[i]) res=mid,r=mid-1;
                else l=mid+1;
            }
            if(res==-1) v[++mx].push_back(a[i]);
            else v[res].push_back(a[i]);
        }
    }
    for(int i=1;i<=mx;++i,puts(""))
        for(int j=0;j<v[i].size();++j)
            printf("%d ",v[i][j]);
    return 0;
}