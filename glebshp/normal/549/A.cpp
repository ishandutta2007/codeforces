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

const int size = 110;
int n, m;

char field[size][size];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    	cin >> field[i];
    int ans = 0;
    string face = "face";
    sort(face.begin(), face.end());
    for (int i = 0; i < n - 1; i++)
    	for (int j = 0; j < m - 1; j++) {
    		string cur;
    		cur += field[i][j];
    		cur += field[i][j + 1];
    		cur += field[i + 1][j];
    		cur += field[i + 1][j + 1];

    		sort(cur.begin(), cur.end());
    		ans += (face == cur);
    	}


    cout << ans << endl;

    return 0;
}