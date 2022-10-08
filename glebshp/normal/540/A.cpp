#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);


int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    string start;
    string finish;

    cin >> n;
    cin >> start;
    cin >> finish;

    int ans = 0;
    for (int i = 0; i < n; i++) {
    	int d = finish[i] - start[i];
    	ans += min(abs(d), 10 - abs(d));
    }

    cout << ans << endl;

    return 0;
}