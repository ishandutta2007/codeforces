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

    string tg = "CODEFORCES";
    string have;

    cin >> have;

    int n = (int) have.size();

	bool flag = false;
    for (int i = 0; i <= n; i++)
    	for (int j = i; j <= n; j++) {
    		if ((string(have.begin(), have.begin() + i) + string(have.begin() + j, have.end())) == tg) {
    			flag = true;
    		}
    	}

    if (flag) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }

    return 0;
}