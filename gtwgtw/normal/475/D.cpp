#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int n,a[100005],b[100005];
map<int,long long>Mp;
int cnt,id[100005];

int gcd(int x,int y)
{
    while(y)
    {
        int tmp=x%y;
        x=y;y=tmp;
    }
    return x;
}

int main()
{
    scanf("%d",&n);
    rep(i,n) scanf("%d",&a[i]);
    rep(c,n)
    {
        for(int i=1;i<=cnt;i++) b[i]=gcd(b[i],a[c]);
        int tmp=0;
        for(int i=1,now;i<=cnt;i=now)
        {
            b[++tmp]=b[i];id[tmp]=id[i];
            for(now=i;b[now]==b[i]&&now<=cnt;now++);
        }
        cnt=tmp;
        b[++cnt]=a[c];
        id[cnt]=c;
        int w=c+1;
        for(int i=cnt;i;i--) Mp[b[i]]+=w-id[i],w=id[i];
    }int q;
    scanf("%d",&q);
    rep(i,q) {int x;scanf("%d",&x);printf("%I64d\n",Mp[x]);}
    return 0;
}