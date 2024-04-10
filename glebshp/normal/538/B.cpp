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

int ans[20];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int pw = 1;
    while (n > 0) {
    	for (int i = 0; i < n % 10; i++) {
    		ans[i] += pw;
    	}

    	pw *= 10;
    	n /= 10;
    }

    int cnt = 0;
    while (ans[cnt] != 0)
    	cnt++;
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
    	cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}