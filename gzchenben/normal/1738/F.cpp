#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,deg[100005],col[100005],ord[100005];
int Ask(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    int tmp;
    scanf("%d",&tmp);
    return tmp;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&deg[i]);
            col[i] = 0;
            ord[i] = i;
        }
        sort(ord+1,ord+n+1,[](int x,int y) -> bool {return deg[x] > deg[y];});
        for(int i=1;i<=n;i++)
        {
            int cur = ord[i];
            if(col[cur]) continue;
            vector<int> fol;
            bool flag=true;
            for(int j=1;j<=deg[cur];j++)
            {
                int tmp = Ask(cur);
                if(col[tmp])
                {
                    flag = false;
                    for(auto &p : fol) col[p] = col[tmp];
                    col[cur] = col[tmp];
                    break;
                }
                fol.push_back(tmp);
            }
            if(flag)
            {
                col[cur] = cur;
                for(auto &p : fol) col[p] = cur;
            }
        }
        printf("!");
        for(int i=1;i<=n;i++) printf(" %d",col[i]);
        printf("\n");
        fflush(stdout);
    }
}