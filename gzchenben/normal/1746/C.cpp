#include<cstdio>
#include<set>
using namespace std;
int n,t,a[100005],ans[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        set<int> st;
        for(int i=1;i<=n;i++)
            st.insert(i),ans[i] = 0;
        for(int i=2;i<=n;i++)
        {
            if(a[i-1] <= a[i]) continue;
            int cur = *st.lower_bound(a[i-1] - a[i]);
            st.erase(cur);
            ans[cur] = i;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d ",ans[i] ? ans[i] : 1);
        }
        printf("\n");
    }
}