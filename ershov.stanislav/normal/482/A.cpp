#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

int n, k;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
    cin >> n >> k;
    for (int i=0; i<k+1; i++) {
        if (i%2) cout << k+1-i/2 << ' ';
        else cout << i/2+1 << ' ';
    }
    for (int i=k+1; i<n; i++) cout << i+1 << ' ';
	return 0;
}