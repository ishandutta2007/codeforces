#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
        int a,b;
};
node t[20000];
int n,k,i;
bool cmp(node a,node b)
{
        if (a.a>b.a) return 1; else return 0;
}
bool cmp2(node a,node b)
{
        if (a.b<b.b) return 1; else return 0;
}
int main()
{
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);

        scanf("%d%d",&n,&k);
        for (i=1;i<=n;i++)
        {
                scanf("%d",&t[i].a); t[i].b=i;
        }
        sort(t+1,t+n+1,cmp);
        printf("%d\n",t[k].a);
        sort(t+1,t+k+1,cmp2);
        for (i=1;i<k;i++) printf("%d ",t[i].b); printf("%d\n",t[k].b);
        return 0;
}