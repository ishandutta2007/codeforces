#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, double> > v;

int main(void)
{
    int n, x;
    int i, j;
    tuple<int, int, double> s;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &x);
        v.push_back(make_tuple(i, i, x));
        while(v.size() >= 2 && get<2>(v.back()) < get<2>(v[v.size() - 2]))
        {
            s = make_tuple(get<0>(v[v.size() - 2]), get<1>(v.back()), (get<2>(v[v.size() - 2]) * (get<1>(v[v.size() - 2]) - get<0>(v[v.size() - 2]) + 1) + get<2>(v.back()) * (get<1>(v.back()) - get<0>(v.back()) + 1)) / (get<1>(v.back()) - get<0>(v[v.size() - 2]) + 1));
            v.pop_back();
            v.pop_back();
            v.push_back(s);
        }
    }

    for(i = 0; i < (signed)v.size(); i ++)
        for(j = get<0>(v[i]); j <= get<1>(v[i]); j ++)
            printf("%.10f ", get<2>(v[i]));
    printf("\n");

    return 0;
}