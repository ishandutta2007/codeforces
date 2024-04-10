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

const int size = 300 * 1000 + 100;

long long nums[size];
long long leftor[size];
long long rightor[size];
int n, k, x;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++) {
    	int num;
    	scanf("%d", &num);
    	nums[i] = num;
    }

    long long multval = 1;
    for (int i = 0; i < k; i++)
    	multval *= x;

    long long ans = 0;
    leftor[0] = 0;
    for (int i = 0; i < n; i++) {
    	leftor[i + 1] = leftor[i] | nums[i];
    }
    rightor[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
    	rightor[i] = rightor[i + 1] | nums[i + 1];
    }

    for (int i = 0; i < n; i++) {
    	ans = max(ans, leftor[i] | rightor[i] | (nums[i] * multval));
    }

    cout << ans << endl;

    return 0;
}