#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,t,a[200005],ans[200005];
bool f[200005];
vector<int> vec[200005],tmp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            f[i]=false;
            vec[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            ans[i]=a[i];
            f[a[i]]=true;
            vec[a[i]].push_back(i);
        }
        tmp.clear();
        for(int i=1;i<=n;i++) if(!f[i]) tmp.push_back(i);
        int top=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<vec[i].size();j++)
            {
                if(vec[i][j]==tmp[top])
                {
                    if(j!=vec[i].size()-1) swap(vec[i][j],vec[i][j+1]);
                    else
                    {
                        ans[vec[i][j]]=ans[vec[i][j-1]];
                        ans[vec[i][j-1]]=tmp[top];
                        top++;
                        break;
                    }
                } 
                ans[vec[i][j]]=tmp[top];
                top++;
            }
        }
        printf("%d\n",n-tmp.size());
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}