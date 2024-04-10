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
const int size = 1000;

int n, h;
int a[size];
int b[size], c[size];

int main() {
/*	
    freopen("input.txt", "w", stdout);
    cout << 200 << ' ' << 10 << endl;
    for (int i = 0; i < 200; i++)
    	cout << rand() % 1000 - 500 << endl;
    return 0;
 */   
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n >> h;
    for (int i = 0; i < n; i++)
    	cin >> a[i];
    int best = a[0];
    for (int i = 0; i < n; i++)
    	for (int j = i; j < n; j++) {
    		int bl = 0;
    		int cl = 0;
    		for (int k = i; k <= j; k++) {
    			b[bl++] = a[k];
    		}
    		for (int k = 0; k < i; k++)
    			c[cl++] = a[k];
    		for (int k = j + 1; k < n; k++)
    			c[cl++] = a[k];
    		sort(b, b + bl);
    		sort(c, c + cl);	
    		int cur = 0;
    		for (int p = 0; p < bl; p++)
    			cur += b[p];

    		best = max(best, cur);
    	   	for (int p = 0; p < min(min(bl, cl), h); p++) {
    	   		cur = cur - b[p] + c[cl - p - 1];
    	   		best = max(best, cur);
    	   	}
    	}

    cout << best << endl;

    return 0;
}