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
const int inf = 2 * 1000 * 1000 * 1000;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    int n;
    vector <pair <int, int> > vec;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	int x, w;
    	scanf("%d%d", &x, &w);
    	vec.pb(mp(x + w, x - w));
    }	

    sort(vec.begin(), vec.end());
    int ans = 0;
    int ptr = -inf;
    for (int i = 0; i < n; i++) {
    	if (vec[i].sc >= ptr) {
    		ans++;
    		ptr = vec[i].fs;
    	}
    }

    cout << ans << endl;

    return 0;
}