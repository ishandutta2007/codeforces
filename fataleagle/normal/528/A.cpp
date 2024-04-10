#include <bits/stdc++.h>

using namespace std;

struct glass
{
    set<int> borders;
    multiset<int> length;
    glass(int N)
    {
        borders.insert(0);
        borders.insert(N);
        length.insert(N);
    }
    void add(int x)
    {
        auto it=borders.lower_bound(x);
        auto it2=it;
        --it2;
        length.erase(length.find(*it-*it2));
        length.insert(*it-x);
        length.insert(x-*it2);
        borders.insert(x);
    }
};

int W, H, N;

int main()
{
    scanf("%d%d%d", &W, &H, &N);
    glass hor(W);
    glass ver(H);
    char op;
    int x;
    while(N--)
    {
        scanf(" %c%d", &op, &x);
        if(op=='H')
            ver.add(x);
        else
            hor.add(x);
        printf("%lld\n", 1LL*(*hor.length.rbegin())*(*ver.length.rbegin()));
    }
    return 0;
}