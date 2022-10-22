#include<cstdio>
#include<vector>
using namespace std;
int n,t,a[200005],cnt[200005];
bool flag[200005];
vector<int> ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans.clear();
        for(int i=0;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        int Now=1;
        while(cnt[0])
        {
            int Maxn=0;
            while(cnt[Maxn]) Maxn++;
            ans.push_back(Maxn);
            for(int i=0;i<Maxn;i++) flag[i]=false;
            int Get=0;
            while(Get!=Maxn)
            {
                cnt[a[Now]]--;
                if(!flag[a[Now]] && a[Now]<Maxn) 
                {
                    flag[a[Now]]=true;
                    Get++;
                }
                Now++;
            }
        }
        while(Now!=n+1)
        {
            Now++;
            ans.push_back(0);
        }
        printf("%d\n",ans.size());
        for(auto &p : ans) printf("%d ",p);
        printf("\n");
    }
}