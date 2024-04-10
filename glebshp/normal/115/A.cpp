#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 100 * 1000;

vector <int> vertex[size];
int deep[size];
bool good[size];

void dfs(int v)
{
    deep[v] = 1;
    int i;
    for (i = 0; i < vertex[v].size(); i++)
    {
        dfs(vertex[v][i]);
        deep[v] = max(deep[vertex[v][i]] + 1, deep[v]);
    }
}

int main()
{
    int n, i, ans, p;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> p;
        good[i] = (p == -1);
        if (p != -1)
            vertex[p - 1].pb(i);
    }

    ans = 0;
    for (i = 0; i < n; i++)
        if (good[i])
        {
            dfs(i);
            ans = max(ans, deep[i]);
        }
    cout << ans;

    return 0;
}