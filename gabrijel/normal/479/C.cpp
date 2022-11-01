#include <bits/stdc++.h>
using namespace std;

int n;
vector <pair <int, int> > test;

int main()
{
    int a, b, tr = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        test.push_back(make_pair(a, b));
    }
    sort(test.begin(), test.end());
    for (int i = 0; i < test.size(); i++)
    {
        if (test [i].second >= tr) tr = test [i].second;
        else tr = test [i].first;
    }
    printf("%d", tr);
    return 0;
}