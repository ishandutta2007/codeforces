#include<cstdio>
#include<vector>
#include<algorithm>
#define mod (1000000007)
using namespace std;
int n,m,to[500005];
vector<int> vec;
int get(int x)
{
    if(to[x]==x) return x;
    else return to[x]=get(to[x]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) to[i]=i;
    for(int i=1;i<=n;i++)
    {
        int k,x,y;
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%d",&x);
            x=get(x);
            if(x!=0) 
            {
                to[x]=0;
                vec.push_back(i);
            }
        }
        if(k==2)
        {
            scanf("%d%d",&x,&y);
            x=get(x);
            y=get(y);
            if(x!=y)
            {
                to[max(x,y)]=min(x,y);
                vec.push_back(i);
            }
        }
    }
    int tmp=1;
    for(int i=1;i<=vec.size();i++) tmp=tmp*2%mod;
    printf("%d %d\n",tmp,vec.size());
    for(int i=0;i<vec.size();i++)
    {
        printf("%d ",vec[i]);
    }
    printf("\n");
}