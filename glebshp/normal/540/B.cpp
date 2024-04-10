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

    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vector <int> marks;
    for (int i = 0; i < k; i++) {
    	int d;
    	cin >> d;
    	marks.pb(d);
    	x -= d;
    } 

   	if (x < n - k) {
   		cout << -1 << endl;
   		return 0;
   	}

   	vector <int> h;

   	while (k < n) {
   		int d = min(y, x - (n - k - 1));
   		marks.pb(d);
   		h.pb(d);

   		x -= d;
   		k++;
   	}

   	sort(marks.begin(), marks.end());
   	if (marks[n / 2] < y) {
   		cout << -1 << endl;
   		return 0;
   	}

   	for (int i = 0; i < (int) h.size(); i++)
   		cout << h[i] << ' ';
   	cout << endl;

    return 0;
}