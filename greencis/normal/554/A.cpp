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
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

string s,ss;
map<string,int> mp;
char z[9];

int main()
{
    cin >> s;
    for (int i = 0; i <= s.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            ss = s;
            *z = 97 + j;
            ss.insert(i, z);
            mp[ss] = 1;
        }
    }
    cout << mp.size();

    return 0;
}