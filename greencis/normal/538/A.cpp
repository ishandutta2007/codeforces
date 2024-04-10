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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

string s;

int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            string ss = s;
            ss.erase(i, j - i + 1);
            if (ss == "CODEFORCES") { cout << "YES"; return 0; }
        }
    }
    cout << "NO";

    return 0;
}