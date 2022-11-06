#include<cstdio>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
 
#define maxn 100010
typedef long long ll;
struct Point
{
    int x,y;
    bool operator<(const Point &a)
    {
        if (a.x!=x) return x<a.x;
        return y<a.y;
    }
    bool operator==(const Point &a)
    {
        return x==a.x && y==a.y;
    }
} point[maxn];
int numx[maxn],numy[maxn],totx,toty;
int n;
set<int> x[maxn],y[maxn];
ll ans;
bool cmp(const Point &a,const Point &b)
{
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
bool find(int x,int y)
{
    int l=1,r=n;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (point[mid]==(Point){x,y}) return true;
        if (point[mid]<(Point){x,y}) l=mid+1;
        else r=mid-1;
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&point[i].x,&point[i].y);
        numx[++totx]=point[i].x;
        numy[++toty]=point[i].y;
    }
    sort(numx+1,numx+totx+1);
    sort(numy+1,numy+toty+1);
    sort(point+1,point+n+1,cmp);
    totx=unique(numx+1,numx+totx+1)-(numx+1);
    toty=unique(numy+1,numy+toty+1)-(numy+1);
    for (int i=1;i<=n;i++)
    {
        int tmp=lower_bound(numx+1,numx+totx+1,point[i].x)-(numx+1);
        x[tmp].insert(point[i].y);
        tmp=lower_bound(numy+1,numy+toty+1,point[i].y)-(numy+1);
        y[tmp].insert(point[i].x);
    }
    for (int i=1;i<=n;i++)
    {
        set<int>::iterator it1,it2;
        int tmp1=lower_bound(numx+1,numx+totx+1,point[i].x)-(numx+1),
            tmp2=lower_bound(numy+1,numy+toty+1,point[i].y)-(numy+1);
        it1=x[tmp1].lower_bound(point[i].y);
        it2=y[tmp2].lower_bound(point[i].x);
        it1++,it2++;
        while (it1!=x[tmp1].end() && it2!=y[tmp2].end())
        {
            if (*it1-point[i].y==*it2-point[i].x)
            {
                if (find(*it2,*it1)) ans++;
                it1++;
                it2++;
                continue;
            }
            if (*it1-point[i].y<*it2-point[i].x) it1++;else it2++;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}