#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
typedef long long ll;
using namespace std;

vector<int> g;
int get()
{
    int guess;
    cin >> guess;
    g.push_back(guess);
    return guess;
}
vector<int> f;
void answer(int x)
{
    cout << x + 1 << endl;
    fflush(stdout);
    f[x] = g.back();
    for (int i = 0; i < f.size() - 1; i++)
    {
        if (f[i] == -1 || f[i + 1] == -1 || f[i] > f[i + 1]) return;
    }
    exit(0);
}
void place_left(int val, int mid)
{
    for (int i = mid; i >= 0; i--)
    {
        if (f[i] == -1 || f[i] < val)
        {
            answer(i);
            return;
        }
    }
    answer(0);
}
void place_right(int val, int mid)
{
    for (int i = mid; i < f.size(); i++)
    {
        if (f[i] == -1 || f[i] > val)
        {
            answer(i);
            return;
        }
    }
    answer(f.size() - 1);
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    int mid = n / 2;
    f.resize(n, -1);
    for (int i = 0; i < m; i++)
    {
        int k = get();
        if (k <= c / 2)
            place_right(k, 0);
        else
            place_left(k, n - 1);
    }
    return 0;
}

// 10 : 27