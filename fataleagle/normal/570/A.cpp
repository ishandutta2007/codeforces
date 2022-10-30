#include <bits/stdc++.h>

using namespace std;

int N, M;
int votes[100];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
    {
        pair<int, int> best=make_pair(-1, 0);
        for(int j=0; j<N; j++)
        {
            int a;
            scanf("%d", &a);
            best=max(best, make_pair(a, -j));
        }
        votes[-best.second]++;
    }
    pair<int, int> win=make_pair(-1, 0);
    for(int i=0; i<N; i++)
        win=max(win, make_pair(votes[i], -i));
    printf("%d\n", -win.second+1);
    return 0;
}