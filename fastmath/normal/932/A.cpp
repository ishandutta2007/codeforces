#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <time.h>

using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    cout << s;
    reverse(s.begin(), s.end());
    cout << s << '\n';

    return 0;
}