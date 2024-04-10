#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const long long mdl = 1000 * 1000 * 1000 + 7;
const int size = 2000 * 1000 + 100;

char buf[size];
long long p[size];

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%s", buf);
    int n = strlen(buf);

    p[0] = 0ll;
    for (int i = 1; i < size; i++) {
    	p[i] = (p[i - 1] * 2 + 1) % mdl;
    }
    long long ans = 0ll;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	if (buf[i] == 'a') {
    		cnt++;
    	} else {
    		ans = (ans + p[cnt]) % mdl;
    	}
    }

    cout << ans << endl;

    return 0;
}