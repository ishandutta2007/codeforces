#include <bits/stdc++.h>

using namespace std;

int N, K, P;
vector<int> even, odd;
vector<vector<int>> outputeven, outputodd;

int main()
{
    scanf("%d%d%d", &N, &K, &P);
    int neven=P;
    int nodd=K-P;
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        if(a%2==0)
            even.push_back(a);
        else
            odd.push_back(a);
    }
    int maxmerge=N-K;
    bool change=true;
    while(change)
    {
        change=false;
        if(!even.empty() && neven>0)
        {
            outputeven.resize(outputeven.size()+1);
            outputeven.back().push_back(even.back());
            even.pop_back();
            neven--;
            change=true;
            continue;
        }
        if(!odd.empty() && nodd>0)
        {
            outputodd.resize(outputodd.size()+1);
            outputodd.back().push_back(odd.back());
            odd.pop_back();
            nodd--;
            change=true;
            continue;
        }
        if(neven>0 && maxmerge>0 && odd.size()>=2)
        {
            outputeven.resize(outputeven.size()+1);
            outputeven.back().push_back(odd.back());
            odd.pop_back();
            outputeven.back().push_back(odd.back());
            odd.pop_back();
            neven--;
            maxmerge--;
            change=true;
            continue;
        }
        if(neven || nodd)
        {
            printf("NO\n");
            return 0;
        }
        if(!outputeven.empty() && !even.empty() && maxmerge>0)
        {
            outputeven.back().push_back(even.back());
            even.pop_back();
            maxmerge--;
            change=true;
            continue;
        }
        if(!outputodd.empty() && !even.empty() && maxmerge>0)
        {
            outputodd.back().push_back(even.back());
            even.pop_back();
            maxmerge--;
            change=true;
            continue;
        }
        if(!outputeven.empty() && odd.size()>1 && maxmerge>1)
        {
            outputeven.back().push_back(odd.back());
            odd.pop_back();
            outputeven.back().push_back(odd.back());
            odd.pop_back();
            maxmerge-=2;
            change=true;
            continue;
        }
        if(!outputodd.empty() && odd.size()>1 && maxmerge>1)
        {
            outputodd.back().push_back(odd.back());
            odd.pop_back();
            outputodd.back().push_back(odd.back());
            odd.pop_back();
            maxmerge-=2;
            change=true;
            continue;
        }
        if(maxmerge==0 && (!even.empty() || !odd.empty()))
        {
            printf("NO\n");
            return 0;
        }
        if(maxmerge>0 && even.empty() && odd.empty())
        {
            printf("NO\n");
            return 0;
        }
    }
    if(maxmerge==0 && even.empty() && odd.empty())
    {
        printf("YES\n");
        for(auto& it: outputeven)
        {
            printf("%d", it.size());
            for(auto& it2: it)
                printf(" %d", it2);
            printf("\n");
        }
        for(auto& it: outputodd)
        {
            printf("%d", it.size());
            for(auto& it2: it)
                printf(" %d", it2);
            printf("\n");
        }
    }
    else
        printf("NO\n");
    return 0;
}