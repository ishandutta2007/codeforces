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

int n,k,u[100005];

int main()
{
    cin >> n >> k;
    bool mnus = false;
    int cur = 1;
    cout << cur << " ";
    u[cur] = 1;
    for (int i = k; i >= 1; --i) {
        if (!mnus) cur += i;
        else cur -= i;
        cout << cur << " ";
        u[cur] = 1;
        mnus = !mnus;
    }
    for (int i = 1; i <= n; ++i)
        if (!u[i]) cout << i << " ";

    return 0;
}