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

const int MAXN = 200000;

bool seen[MAXN];

int main(){
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            seen[i] = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x += i;
            x = (x % n + n) % n;
            seen[x] = true;
        }
        bool bad = false;
        for (int i = 0; i < n; i++)
            if (!seen[i])
                bad = true;
        if (bad)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}