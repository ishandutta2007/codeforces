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
const int MAXN = 100100;

int N, M;
int a[MAXN];
pair <int, int> v[MAXN];
int ps[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort (v, v + M);
    ps[0] = 0;
    for (int i = 0; i < M; i++)
    {
        ps[i+1] = ps[i] + v[i].second;
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        if (a[i] < v[0].first)
        {
            cout << 0;
            continue;
        }

        int lo = 0, hi = M - 1;
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            if (a[i] < v[mid].first)
                hi = mid - 1;
            else
                lo = mid;
        }
        cout << ps[lo+1];
    }
    cout << "\n";
}