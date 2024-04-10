#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXM = 1000100;

int N, M;
int par[MAXM];
pair <pair <int, int>, int> arr[MAXM];

int cfind (int a)
{
    if (par[a] == a) return a;
    return par[a] = cfind (par[a]);
}

void uni (int a, int b)
{
    a = cfind (a);
    b = cfind (b);
    par[a] = b;
}

inline bool cmp (pair <pair <int, int>, int> left, pair <pair <int, int>, int> right)
{
    return left.second < right.second;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        par[i] = i;

    for (int i = 0; i < M; i++)
    {
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
    }
    sort (arr + 1, arr + M, cmp);

    int x = arr[0].first.first, y = arr[0].first.second;
    for (int i = 1; i < M; i++)
    {
        uni (arr[i].first.first, arr[i].first.second);
        if (cfind (x) == cfind (y))
        {
            cout << arr[i].second << "\n";
            return 0;
        }
    }
    cout << 1000000000 << "\n";
}