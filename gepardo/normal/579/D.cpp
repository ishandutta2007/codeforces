#include <iostream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

long long a[300000];
long long k, x, n, o = -1, p = 1;
long long bits[62] = {};

void rec_bits(long long q, long long delta)
{
    long long p = 1;
    for (long long i = 0; i < 62; i++)
    {
        long long v = q & p;
        if (v != 0) bits[i] += delta;
        p *= 2;
    }
}

long long answ()
{
    long long res = 0;
    long long p = 1;
    for (long long i = 0; i < 62; i++)
    {
        if (bits[i] != 0) res += p;
        p *= 2;
    }
    return res;
}

int main()
{
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) p *= x;
    for (int i = 0; i < n; i++) rec_bits(a[i], 1);
    for (int i = 0; i < n; i++)
    {
        rec_bits(a[i], -1);
        rec_bits(a[i] * p, 1);
        if (answ() > o) o = answ();
        rec_bits(a[i], 1);
        rec_bits(a[i] * p, -1);
    }
    cout << o << endl;
    return 0;
}