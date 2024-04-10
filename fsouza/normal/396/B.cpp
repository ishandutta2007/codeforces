#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

typedef long long lint;

using namespace std;

lint gcd(lint a, lint b) {
        if (a == 0) return b;
        return gcd(b%a, a);
}

bool prime(int v)
{
        if (v == 2) return true;
        if (v%2 == 0) return false;

        for (int x = 3; x*x <= v; x += 2)
                if (v%x == 0)
                        return false;

        return true;
}

int main(int argc, char ** argv)
{
        int nt;

        cin >> nt;

        for (int t = 0; t < nt; t++) {
                lint n;
                cin >> n;

                lint prev = n, next = n+1;

                while (!prime(prev)) prev--;
                while (!prime(next)) next++;

                lint a = prev*next + 2LL*(n-prev+1) - 2LL*next;
                lint b = 2*next*prev;
                lint g = gcd(a, b);

                a /= g;
                b /= g;

                cout << a << "/" << b << endl;
        }

        return 0;
}