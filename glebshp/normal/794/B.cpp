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

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    double h;

    cin >> n >> h;

//    double area = h / 2.0;

    for (int i = 1; i < n; i++) {
    	double curh = h * sqrt(i * 1.0 / n);
    	printf("%.20lf%c", curh, " \n"[i == n - 1]);
    }

    return 0;
}