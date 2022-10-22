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
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, char> c;
    int cnteven = 0, cntodd = 0;
    for (int i = 0; i < q; i++)
    {
        char qu;
        cin >> qu;
        if (qu == '+')
        {
            int a, b; char ch;
            cin >> a >> b >> ch;
            c[{a, b}] = ch;
            if (c.count({ b,a }))
            {
                cntodd++;
                if (c[{b, a}] == ch) cnteven++;
            }
        }
        else if (qu == '-')
        {
            int a, b;
            cin >> a >> b;
            if (c.count({ b,a }))
            {
                cntodd--;
                if (c[{b, a}] == c[{a, b}]) cnteven--;
            }
            c.erase({ a, b });
        }
        else
        {
            int k; cin >> k;
            if (k & 1) cout << (cntodd > 0 ? "YES\n" : "NO\n");
            else cout << (cnteven > 0 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}