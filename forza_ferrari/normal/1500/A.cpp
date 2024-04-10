#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,t[2500001];
pair<int,int> a[100001],num[2500001];
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
    {
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for(register int i=2;i<=n;++i)
        for(register int j=1;j<i-1;++j)
            if(t[a[i].first-a[j].first]++&&num[a[i].first-a[j].first].first&&num[a[i].first-a[j].first].second)
            {
                if(num[a[i].first-a[j].first].second!=a[j].second&&num[a[i].first-a[j].first].second!=a[i].second&&num[a[i].first-a[j].first].first!=a[j].second&&num[a[i].first-a[j].first].first!=a[i].second)
                {
                    puts("YES");
                    printf("%d %d %d %d\n",num[a[i].first-a[j].first].first,a[i].second,num[a[i].first-a[j].first].second,a[j].second);
                    return 0;
                }
            }
            else
                num[a[i].first-a[j].first]=make_pair(a[j].second,a[i].second);
    puts("NO");
    return 0;
}