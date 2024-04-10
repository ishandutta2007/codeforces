#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

long long a,b,c;
long long res[1001005],curidx;

int main()
{
    cin >> a >> b >> c;
    for (long long i = 1; i <= 81; ++i) {
        long long cur = 1ll;
        for (int j = 0; j < a; ++j)
            cur *= i;
        cur *= b;
        cur += c;
        long long sum = 0, cur2 = cur;
        if (cur2 <= 0) continue;
        while (cur2) {
            sum += cur2 % 10;
            cur2 /= 10;
        }
        if (sum == i && cur > 0 && cur < 1000*1000*1000ll)
            res[curidx++] = cur;
    }
    sort(res,res+curidx);
    cout << curidx << endl;
    for (int i = 0; i < curidx; ++i)
        cout << res[i] << " ";

    return 0;
}