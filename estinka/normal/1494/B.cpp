#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <list>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        array<int, 4> a;
        cin >> n >> a[0] >> a[1] >> a[2] >> a[3];
        bool can = false;
        for (int i = 0; i < (1 << 4); i++)
        {
            array<int, 4 > a2 = a;
            for (int j = 0; j < 4; j++)
            {
                if ((1 << j) & i)
                {
                    a2[j]--;
                    a2[(j + 1) % 4]--;
                }
            }
            if (*min_element(a2.begin(), a2.end()) >= 0 && *max_element(a2.begin(), a2.end()) <= n - 2)
            {
                can = true;
                break;
            }
        }
        cout << (can ? "YES\n" : "NO\n");
    }
    return 0; 
}