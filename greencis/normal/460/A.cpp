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

int n,m,res,cur;

int main()
{
    cin >> n >> m;
    while (n--) {
        ++cur;
        if (cur % m == 0) ++n;
    }
    cout << cur;

    return 0;
}