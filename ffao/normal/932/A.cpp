#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define all(v) (v).begin(), (v).end()

#include <iostream>

string s;
void solve()
{
    cin >> s;
    string r = s;
    reverse(all(r));
    cout << s << r;
}

int main() {

    solve();
}