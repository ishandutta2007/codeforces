#include <bits/stdc++.h>

using namespace std;

int N, M, T;
int A[20000];
int rans;
vector<int> ans;
set<pair<int, int>> online;
multiset<pair<int, int>> events;

bool solve()
{
    bool good=false;
    for(int i=0; i<N; i++)
        events.insert({A[i], -1});
    while(!events.empty())
    {
        int t=events.begin()->first;
        int v=events.begin()->second;
        events.erase(events.begin());
        if(v==-1)
        {
            if((int)online.size()<M)
            {
                rans++;
                online.insert({t+T-1, rans});
                events.insert({t+T-1, rans});
                ans.push_back(rans);
            }
            else
            {
                pair<int, int> guy=*online.rbegin();
                online.erase(guy);
                events.erase(events.find(guy));
                guy.first=t+T-1;
                online.insert(guy);
                events.insert(guy);
                ans.push_back(guy.second);
            }
            good|=(int)online.size()==M;
        }
        else
            online.erase({t, v});
    }
    return good;
}

int main()
{
    scanf("%d%d%d", &N, &M, &T);
    int hh, mm, ss;
    for(int i=0; i<N; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        A[i]=hh*3600+mm*60+ss;
    }
    if(!solve())
        printf("No solution\n");
    else
    {
        printf("%d\n", rans);
        for(auto& it: ans)
            printf("%d\n", it);
    }
    return 0;
}