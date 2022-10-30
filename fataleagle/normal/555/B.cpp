#include <bits/stdc++.h>

using namespace std;

int N, M;
long long L[200000], R[200000];
map<pair<long long, long long>, vector<int>> m1;
map<long long, vector<int>> m2;
int ans[200000];

int main()
{
    scanf("%d%d", &N, &M);
    vector<pair<long long, long long>> v;
    for(int i=0; i<N; i++)
    {
        scanf("%lld%lld", L+i, R+i);
        if(i>0)
        {
            v.push_back({L[i]-R[i-1], R[i]-L[i-1]});
            m1[v.back()].push_back(i);
        }
    }
    multiset<long long> s;
    for(int i=0; i<M; i++)
    {
        long long a;
        scanf("%lld", &a);
        s.insert(a);
        m2[a].push_back(i+1);
    }
    sort(v.begin(), v.end(), [](const pair<long long, long long>& a, const pair<long long, long long>& b){
         if(a.second!=b.second)
            return a.second<b.second;
         return a.first<b.first;
    });
    for(auto& it: v)
    {
        auto it2=s.lower_bound(it.first);
        if(it2!=s.end() && *it2<=it.second)
        {
            ans[m1[it].back()]=m2[*it2].back();
            m1[it].pop_back();
            m2[*it2].pop_back();
            s.erase(it2);
        }
        else
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    for(int i=1; i<N; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}