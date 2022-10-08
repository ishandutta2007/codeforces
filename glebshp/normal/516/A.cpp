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
const int size = 100;

int n;
char buf[size];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    scanf("%s", buf);

    vector <int> ans;
    for (int i = 0; i < n; i++) {
    	if (buf[i] == '2') {
    		ans.pb(2);
    	}
    	if (buf[i] == '3') {
    		ans.pb(3);
    	}
    	if (buf[i] == '4') {
    		ans.pb(3);
    		ans.pb(2);
    		ans.pb(2);
    	}
    	if (buf[i] == '5') {
    		ans.pb(5);
    	}
    	if (buf[i] == '6') {
    		ans.pb(5);
    		ans.pb(3);
    	}
    	if (buf[i] == '7') {
    		ans.pb(7);
    	}
    	if (buf[i] == '8') {
    		ans.pb(7);
    		ans.pb(2);
    		ans.pb(2);
    		ans.pb(2);
    	}
    	if (buf[i] == '9') {
    		ans.pb(7);
    		ans.pb(3);
    		ans.pb(3);
    		ans.pb(2);
    	}
    }

    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < (int) ans.size(); i++)
    	printf("%d", ans[i]);
    printf("\n");

    return 0;
}