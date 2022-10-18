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

int n,m,a,b;

int main()
{
    cin >> n >> m >> a >> b;
    if (b > a*m) {
        cout << n * a;
    } else {
        cout << min((n / m) * b + (n % m) * a, ((n + m - 1) / m) * b);
    }

    return 0;
}