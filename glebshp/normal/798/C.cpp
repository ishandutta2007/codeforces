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

const int size = 100 * 1000 + 1;

int n;
int a[size];

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    }

    cout << "YES" << endl;

    int d = 0;
    for (int i = 0; i < n; i++) {
    	d = gcd(d, a[i]);
    }

    if (d > 1) {
    	cout << 0 << endl;
    	return 0;
    }

    int ans = 0;
    int i = 0, j = 0;
   	while (i < n) {
   		while (i < n && a[i] % 2 == 0)
   			i++;
   		if (i < n) {
   			j = i;
   			while (j < n && a[j] % 2 == 1) 
   				j++;
   			if ((j - i) & 1) {
   				ans += (j - i + 1) / 2 + 1;
   			} else {
   				ans += (j - i) / 2;
   			}

   			cerr << i << ' ' << j << endl;

   			i = j;
   		}
   	}

   	cout << ans << endl;

    return 0;
}