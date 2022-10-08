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
#define double long double

int n;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> n;
    vector <double> probs;
    for (int i = 0; i < n; i++) {
    	double d;
    	cin >> d;
    	probs.pb(d);
    }

    sort(probs.rbegin(), probs.rend());
    double a = 0.0;
    double b = 1.0;
    for (int i = 0; i < n; i++) {
    	double na = probs[i] * b + (1 - probs[i]) * a;
    	double nb = (1 - probs[i]) * b;
    	if (na > a) {
    		a = na;
    		b = nb;
    	}
    }

    cout.precision(20);
    cout << a << endl;

    return 0;
}