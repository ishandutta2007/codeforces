#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, a, b;
int v[205][5005]; /// TAKEN/ZEROES (count twos)
int u[205][5005]; /// TAKEN/ZEROES (count fives)
ll x;

int main()
{
    cin >> n >> k;
    v[0][0] = 1;
    u[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a = b = 0;
        while (x % 2 == 0)
            ++a, x /= 2;
        while (x % 5 == 0)
            ++b, x /= 5;
        /// if we take
        for (int taken = min(i, k - 1); taken >= 0; --taken) {
            for (int zeroes = 25 * i; zeroes >= 0; --zeroes) {
                if (u[taken][zeroes]) {
                    int new_zeroes = zeroes + min(u[taken][zeroes] - 1 + a, b);
                    int balance = u[taken][zeroes] - 1 + a - b;
                    if (balance >= 0)
                        u[taken + 1][new_zeroes] = max(u[taken + 1][new_zeroes], balance + 1);
                    if (balance <= 0)
                        v[taken + 1][new_zeroes] = max(v[taken + 1][new_zeroes], -balance + 1);
                }
                if (v[taken][zeroes]) {
                    int new_zeroes = zeroes + min(v[taken][zeroes] - 1 + b, a);
                    int balance = -(v[taken][zeroes] - 1) + a - b;
                    if (balance >= 0)
                        u[taken + 1][new_zeroes] = max(u[taken + 1][new_zeroes], balance + 1);
                    if (balance <= 0)
                        v[taken + 1][new_zeroes] = max(v[taken + 1][new_zeroes], -balance + 1);
                }
            }
        }
    }
    for (int i = 5000; i >= 0; --i) {
        if (v[k][i] || u[k][i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}