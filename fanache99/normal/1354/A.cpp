#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

int main() {
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a <= b)
            cout << b << "\n";
        else {
            a -= b;
            if (d >= c)
                cout << "-1\n";
            else {
                long long x = (a - 1) / (c - d) + 1;
                cout << b + x * c << "\n";
            }
        }
    }
    return 0;
}