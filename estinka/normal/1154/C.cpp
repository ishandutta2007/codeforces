#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll what[7] = { 1,2,3,1,3,2,1 };
ll when_will_I_run_out(ll x, ll day, ll how_much)
{
    // Returns how many days it'll take to run
    // out of food x.
    ll when = 0;
    for (int i = day; i < 7; i++)
    {
        if (what[i] == x)
        {
            if (!how_much)
            {
                return when;
            }
            how_much--;
        }
        when++;
    }
    ll c = count(what, what + 7, x);
    when += (how_much / c) * 7;
    how_much %= c;
    for (int i = 0; i < 7; i++)
    {
        if (what[i] == x)
        {
            if (!how_much)
            {
                return when;
            }
            how_much--;
        }
        when++;
    }
    return when;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll answer = 0;
    for (int day = 0; day < 7; day++)
    {
        answer = max(answer, min({ when_will_I_run_out(1, day, a), when_will_I_run_out(2, day, b), when_will_I_run_out(3, day, c) }));
    }
    cout << answer << "\n";
    return 0;
}