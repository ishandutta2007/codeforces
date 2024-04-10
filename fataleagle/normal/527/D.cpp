#include <bits/stdc++.h>

using namespace std;

int N;
pair<long long, long long> intervals[200000];

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        intervals[i]=make_pair(0LL+a+b, 0LL+a-b);
    }
    sort(intervals, intervals+N);
    int ans=0;
    long long far=-0x3f3f3f3f3f3f3f3fLL;
    for(int i=0; i<N; i++) if(intervals[i].second>=far)
        ans++, far=intervals[i].first;
    printf("%d\n", ans);
    return 0;
}