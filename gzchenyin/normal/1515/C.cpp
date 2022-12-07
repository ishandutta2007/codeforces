#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k,t,h[100005];
struct node
{
    int id,val;
};
bool operator <(node x,node y)
{
    return x.val>y.val;
}
priority_queue<node> Q;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
        }
        for(int i=1;i<=m;i++)
        {
            Q.push((node){i,0});
        }
        printf("YES\n");
        for(int i=1;i<=n;i++)
        {
            node tmp=Q.top();
            printf("%d ",tmp.id);
            Q.pop();
            tmp.val+=h[i];
            Q.push(tmp);
        }
        printf("\n");
        for(int i=1;i<=m;i++)
        {
            Q.pop();
        }
    }
}