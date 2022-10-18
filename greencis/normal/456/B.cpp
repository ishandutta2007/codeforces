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

char num[101005];
int a[9],r;

int main()
{
    cin >> num;
    int nlen = strlen(num);
    for (int i = 0; i < nlen; ++i) {
        r = (r * 10 + num[i] - '0') % 4;
    }

    if (r == 0) cout << 4;
    else cout << 0;

    return 0;
}