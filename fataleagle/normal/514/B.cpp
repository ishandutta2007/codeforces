#include <bits/stdc++.h>

using namespace std;

int N, x, y;
set<pair<int, int>> m;

int main()
{
    scanf("%d%d%d", &N, &x, &y);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        a-=x;
        b-=y;
        int g=__gcd(abs(a), abs(b));
        a/=g;
        b/=g;
        if(a<0 || (a==0 && b<0))
            a*=-1, b*=-1;
        m.insert({a, b});
    }
    printf("%d\n", m.size());
    return 0;
}