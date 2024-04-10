#include <bits/stdc++.h>

using namespace std;

int N;
int F[100001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", F+i);
    set<pair<int, int>> s;
    for(int i=1; i<=N; i++)
    {
        int x=F[F[i]];
        int y=F[F[F[i]]];
        if(x>y)
            swap(x, y);
        s.insert({x, y});
    }
    printf("%d\n", (int)s.size());
    return 0;
}