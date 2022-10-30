#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int H, Q;
vector<pair<long long, long long>> ok, not_ok;
set<pair<long long, long long>> intervals;

int main()
{
    scanf("%d%d", &H, &Q);
    long long a, b, c, d;
    while(Q--)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        b*=1LL<<(H-a);
        c++;
        c*=1LL<<(H-a);
        c--;
        if(d)
            ok.push_back(make_pair(b, c));
        else
            not_ok.push_back(make_pair(b, c));
    }
    long long l=1LL<<(H-1), r=(1LL<<H)-1;
    for(auto& it: ok)
        l=max(l, it.first), r=min(r, it.second);
    if(l>r)
    {
        printf("Game cheated!\n");
        return 0;
    }
    intervals.insert(make_pair(l, r));
    for(auto& it: not_ok)
    {
        auto it2=intervals.lower_bound(make_pair(it.first, -1));
        while(it2!=intervals.end() && it2->first<=it.second)
        {
            long long nl=it.second+1, nr=it2->second;
            if(nl<=nr)
                intervals.insert(make_pair(nl, nr));
            intervals.erase(it2);
            it2=intervals.lower_bound(make_pair(it.first, -1));
        }
        it2=intervals.lower_bound(make_pair(it.first, -1));
        if(it2!=intervals.begin() && it2->first>it.first)
            --it2;
        if(it2!=intervals.end() && it2->second>=it.first && it2->first<=it.first)
        {
            long long nl=it2->first, nr=it.first-1;
            if(nl<=nr)
                intervals.insert(make_pair(nl, nr));
            nl=it.second+1, nr=it2->second;
            if(nl<=nr)
                intervals.insert(make_pair(nl, nr));
            intervals.erase(it2);
        }
    }
    if(intervals.empty())
        printf("Game cheated!\n");
    else if(intervals.size()>1 || intervals.begin()->first!=intervals.begin()->second)
        printf("Data not sufficient!\n");
    else
        printf("%lld\n", intervals.begin()->first);
    return 0;
}