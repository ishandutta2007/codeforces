#include<bits/stdc++.h>
using namespace std;

int n, cnt;
pair<int, int> p[100001];
vector<int> child[100001];

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &p[i].first, &p[i].second);

        if(p[i].first!=-1) child[p[i].first].push_back(i);
    }

    for(int i=1; i<=n; i++)
    {
        if(p[i].second==0) continue;

        bool isRespect=false;
        for(int j=0; j<child[i].size(); j++)
        {
            int next = child[i][j];

            if(p[next].second==0) isRespect=true;
        }
        if(isRespect) continue;

        for(int j=0; j<child[i].size(); j++)
        {
            int next = child[i][j];

            p[next].first=p[i].first;
        }

        printf("%d ", i);
        cnt++;
    }

    if(cnt==0) printf("-1");
}