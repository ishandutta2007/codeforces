#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define MN 300000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
pair<int,int> a[MN+5];
int n,x1,x2,can[MN+5];
int Find(int x,int y)
{
    int l=1,r=n,mid,res=n+1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(1LL*a[mid].first*y>=x) res=mid,r=mid-1;
        else l=mid+1;
    }
    return res;
}
int rev=0;
void Solve()
{
    memset(can,0,sizeof(can));
    for(int i=1;i<=n;++i)
    {
        int index=Find(x2,i);
        if(index+i-1<=n) can[n-i+1]=i;
    }
    for(int i=n-1;i>0;--i) can[i]=can[i+1]?can[i+1]:can[i];
    for(int i=1;i<=n;++i)
    {
        int index=Find(x1,i);
        if(index+i-1>=n) continue;
        int nxindex=index+i;
        if(can[nxindex])
        {
            puts("Yes");
            if(!rev) printf("%d %d\n",i,can[nxindex]);
            else printf("%d %d\n",can[nxindex],i);
            if(!rev) {for(int j=index,k=1;k<=i;++k,++j) printf("%d ",a[j].second);puts("");}
            for(int j=n,k=1;k<=can[nxindex];++k,--j) printf("%d ",a[j].second);puts("");
            if(rev) {for(int j=index,k=1;k<=i;++k,++j) printf("%d ",a[j].second);puts("");}
            exit(0);
        }
    }
}
int main()
{
    n=read();x1=read();x2=read();
    for(int i=1;i<=n;++i) a[i].first=read(),a[i].second=i;
    sort(a+1,a+n+1);
    Solve();
    rev=1;swap(x1,x2);
    Solve();
    puts("No");
    return 0;
}