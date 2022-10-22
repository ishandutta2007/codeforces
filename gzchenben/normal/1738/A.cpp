#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        vector<int> v[2];
        long long sum = 0;
        for(int i=1;i<=n;i++)
        {
            v[a[i]].push_back(b[i]);
            sum += b[i];
        }
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        if(v[0].size() == v[1].size())
        {
            printf("%lld\n",2*sum - min(v[0][0],v[1][0]));
        }
        else
        {
            reverse(v[0].begin(),v[0].end());
            reverse(v[1].begin(),v[1].end());            
            for(int i=0;i<v[0].size() && i<v[1].size();i++)
                sum += v[0][i] + v[1][i];
            printf("%lld\n",sum);
        }
    }
}