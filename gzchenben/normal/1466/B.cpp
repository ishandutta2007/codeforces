#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,t,a[100005],cnt[200005];
vector<int> vec;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        bool flag=false;
        int now=0,ans=0,tmp=n;
        for(int i=1;i<=2*n+1;i++)
        {
            if(cnt[i]>0) ans++;
            if(flag && cnt[i]==0)
            {
                vec.push_back(now+1);
                flag=false;
            }
            if(flag && cnt[i]==1)
            {
                now++;
            }
            if(cnt[i]>1) 
            {
                flag=true;
                now=0;
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++)
        {
            if(tmp>vec[i])
            {
                tmp-=vec[i];
                ans++;
            }
            else break;
        }
        printf("%d\n",ans);
        vec.clear();
        for(int i=1;i<=2*n;i++) cnt[i]=0;
    }
}