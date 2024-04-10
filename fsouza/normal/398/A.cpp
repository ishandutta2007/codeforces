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
#define INFLL 10000000000000000

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
        int a, b;
        lint result = -INFLL;
        string s;

        cin >> a >> b;

        if (a == 0) result = -(lint)b*b, s = string(b, 'x');
        else if (b == 0) result = (lint)a*a, s = string(a, 'o');
        else {
                for (int rep = 0; rep < 2; rep++) {
                        for (int na = 1; na <= a; na++)
                                for (int nb = max(na-1, 1); nb <= min(na+1, nb); nb++) {
                                        lint res = 0;

                                        res += (na-1) * 1 * 1;
                                        res += 1LL * (a - (na-1)) * (a - (na-1));

                                        int q = b/nb, r = b%nb;

                                        res -= (lint)r * (q+1) * (q+1);
                                        res -= (lint)(nb-r) * q * q;

                                        result = max(result, res);

                                        if (res == result && rep == 1) {
                                                vector <int> sizes[2];

                                                sizes[0].push_back(a - (na-1));
                                                for (int i = 0; i < na-1; i++) sizes[0].push_back(1);

                                                for (int i = 0; i < r; i++) sizes[1].push_back(q+1);
                                                for (int i = 0; i < nb-r; i++) sizes[1].push_back(q);

                                                s = string(a+b, '_');

                                                int turn = nb > na, pos = 0;

                                                while (!sizes[turn].empty()) {
                                                        for (int k = 0; k < sizes[turn].back(); k++) s[pos++] = "ox"[turn];
                                                        sizes[turn].pop_back();
                                                        turn ^= 1;
                                                }

                                                goto end;
                                        }
                                }


                }
        }

end:
        cout << result << endl;
        cout << s << endl;

        return 0;
}