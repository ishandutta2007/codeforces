#include <bits/stdc++.h>

using namespace std;

int ask(int w)
{
    cout << "? " << w << endl;
    int h;
    cin >> h;
    return h;
}

void answer(int area)
{
    cout << "! " << area << endl;
    exit(0);
}

int main()
{
    int N; scanf("%d", &N);

    int lo = 0, hi = N*2001;
    while(lo+1!=hi)
    {
        int mi = (lo+hi)/2;
        if(ask(mi) != 1) lo = mi;
        else hi = mi;
    }
    int ans = hi;
    for(int h=2; h<=N; h++)
    {
        int w = hi/h;
        int v = ask(w);
        if(v) ans = min(ans, w*v);
    }
    answer(ans);
    return 0;
}