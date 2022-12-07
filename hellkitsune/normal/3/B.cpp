#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct s
{
    int id, p;
    s() {}
    s(int a, int b)
    {
        id = a;
        p = b;
    }
};

bool operator < (const s &a, const s &b)
{
    return a.p < b.p;
}

int n, v;
vector<s> b, k;

int main(void)
{
    int t, p;
    cin >> n >> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> t >> p;
        if (t == 1)
            b.push_back(s(i + 1, -p));
        else
            k.push_back(s(i + 1, -p));
    }
    sort(b.begin(), b.end());
    sort(k.begin(), k.end());
    for (int i = 0; i < (int)b.size(); ++i)
        b[i].p *= -1;
    for (int i = 0; i < (int)k.size(); ++i)
        k[i].p *= -1;
    unsigned bi = 0, ki = 0;
    long long answ = 0, bp, kp;
    stringstream ss;
    if ((v % 2) && (b.size()))
    {
        answ += b[0].p;
        ss << b[bi++].id << ' ';
    }
    while (v > 1)
    {
        bp = 0;
        if (bi < b.size())
            bp += b[bi].p;
        if (bi + 1 < b.size())
            bp += b[bi + 1].p;
        if (ki < k.size())
            kp = k[ki].p;
        else
            kp = 0;
        if (bp + kp == 0)
            break;
        if (kp > bp)
        {
            v -= 2;
            answ += kp;
            ss << k[ki++].id << ' ';
        }
        else
        {
            answ += bp;
            ss << b[bi++].id << ' ';
            --v;
            if (bi < b.size())
            {
                --v;
                ss << b[bi++].id << ' ';
            }
        }
    }
    cout << answ << endl;
    cout << ss.str() << endl;
    return 0;
}