#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<pair<int, int> > candy[2];

int solve(int c)
{
    int h=X;
    int ret=0;
    priority_queue<int> good[2];
    size_t idx[2]={0, 0};
    while(1)
    {
        while(idx[c]<candy[c].size() && candy[c][idx[c]].first<=h)
            good[c].push(-candy[c][idx[c]++].second);
        if(good[c].empty())
            break;
        h+=good[c].top();
        good[c].pop();
        c^=1;
        ret++;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &X);
    int a, b, c;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        candy[a].push_back(make_pair(b, -c));
    }
    sort(candy[0].begin(), candy[0].end());
    sort(candy[1].begin(), candy[1].end());
    printf("%d\n", max(solve(0), solve(1)));
    return 0;
}