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

    vector <long long> nums;
    int n;
    long long d;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%I64d", &d);
    	nums.pb(d);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int) nums.size(); i++) {
    	sum += nums[i] * (i + 2);
    }
    sum -= nums.back();

    cout << sum << endl;

    return 0;
}