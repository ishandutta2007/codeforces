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

int n,p,q,ans;

int main()
{
    cin >> n;
    while (n--) {
        cin >> p >> q;
        if (p + 2 <= q) ++ans;
    }
    cout << ans;

    return 0;
}