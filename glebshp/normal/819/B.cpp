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

const int size = 1000 * 1000 + 100;

int p[size];
vector <int> myshift[size];
long long val[size];
int n;

int main () {
//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    long long der = 0ll;
    for (int i = 0; i < n; i++) {
    	scanf("%d", &p[i]);
    	p[i]--;

    	int d = p[i] - i;
    	if (d < 0)
    		d += n;
    	myshift[d].pb(i);

    	if (i <= p[i])
    		der -= 1;
    	else
    		der += 1;	
    }

	for (int i = 0; i < n; i++)
		val[0] += abs(p[i] - i);
	for (int i = 0; i < n; i++) {
//		cerr << i << ' ' << der << endl;
		val[i + 1] = val[i];
		val[i + 1] -= abs(p[n - 1 - i] - (n - 1)) - 1;
		val[i + 1] += abs(p[n - 1 - i]);
		der -= 2;
		der += 2 * (int) myshift[i].size();

		val[i + 1] += der;

//		cerr << i + 1 << ' ' << val[i + 1] << ' ' << der << endl;
	}

	int b = 0;
	for (int i = 1; i < n; i++) {
		if (val[i] < val[b])
			b = i;
	}

	printf("%lld %d\n", val[b], b);

    return 0;
}