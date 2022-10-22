#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <array>
#include <bitset>
#include <stack>
typedef long long ll;
typedef long double ld;
using namespace std;

int ask(int y)
{
    //cout << " <<< ";
    cout << y << endl;
    cout.flush();
    //return 1;
    int x;
    cin >> x;
    if (x == 0 || x == -2) exit(0);
    return x;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> lie(n);
    for (int i = 0; i < n; i++)
    {
        lie[i] = ask(m);
        if (lie[i] == 1) lie[i] = 0;
        else lie[i] = 1;
    }
    int lo = 1, hi = m, i = 0;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        int ans = ask(mid);
        if (!lie[i % n]) ans *= -1;
        if (ans == -1) hi = mid;
        else lo = mid + 1;
        i++;
    }
    ask(lo);
    return 0;
}