#include <bits/stdc++.h>

using namespace std;

long long x;

int main()
{
    scanf("%lld", &x);
    vector<pair<long long, long long>> ans;
    long long sum=0;
    for(int i=1; sum<=x; i++)
    {
        sum+=1LL*i*i;
        long long d=x-sum;
        long long k=1LL*i*(i+1)/2;
        if(d%k==0)
        {
            ans.push_back({i, d/k+i});
            ans.push_back({d/k+i, i});
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end())-ans.begin());
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%lld %lld\n", it.first, it.second);
    return 0;
}