#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#include <complex>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

typedef complex<double> C;

void FFT(C *a, C *A, int n, bool rev) {
    //for (int i = 0; i < n; ++i) {
        //if (a[i].real() == 1) printf("%d ", i);
    //}
    //printf("\n");
    //puts("here");
    int lg2n = 1;
    while ((1<<lg2n) != n) ++lg2n;
    //printf("%d: %d\n", n, lg2n);
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; j < lg2n; ++j) {
            if (i&(1<<j)) x |= 1<<(lg2n - 1 - j);
        }
        A[x] = a[i];
    }
    for (int s = 1; s <= lg2n; ++s) {
        int m = 1<<s;
        long double p = pi * 2 / m * (rev ? -1: 1);
        C wm(cos(p), sin(p));
        for (int k = 0; k < n; k += m) {
            C w(1);
            int b = m >> 1;
            for (int j = 0; j < b; ++j) {
                C t = w * A[k + j + b];
                A[k + j + b] = A[k + j] - t;
                A[k + j] += t;
                w *= wm;
            }
        }
    }
    if (rev) {
        C tmp(1.0 / n);
        for (int i = 0; i < n; ++i) {
            A[i] *= tmp;
            //A[i].real() /= n, A[i].imag() /= n;
        }
    }
}

int n, m;
C u[4000007], x[4000007];

int arr[4000007];
int arr1[4000007];

int main() {
	cin >> n >> m;
	REP(i, n) {
		int x;
		scanf("%d", &x);
		arr[x] = 1;
	}
	arr[0] = 1;

	int bound = 1;
    while (bound <= m*2+2) bound <<= 1;
	REP(i, bound) u[i] = arr[i];
    FFT(u, x, bound, false);
    REP(i, bound) x[i] *= x[i];
    FFT(x, u, bound, true);
    REP(i, m + 1) arr1[i] = (int)(u[i].real() + 0.5);

    for (int i = 1; i <= m; ++i) {
    	if (i % 2 == 0) {
    		if (arr[i / 2]) {
    			++arr1[i];
    		}
    	}
    }
    REP(i, m + 1) arr1[i] /= 2;
    // REP(i, bound) cout << arr[i] << " ";
    // cout << endl;
    // REP(i, bound) cout << arr1[i] << " ";
    // cout << endl;

    bool sol = true;
    vector<int> ans;
    REP(i, m + 1) {
    	if (!i) continue;
    	if ((arr1[i] > 0) ^ (arr[i] > 0)) {
    		sol = false;
    		break;
    	}

    	if (arr1[i] == 1 && i) {
    		ans.push_back(i);
    	}
    }

    if (sol) 
    	puts("YES"); 
    else puts("NO");

    if (sol) {
    	cout << ans.size() << endl;
    	TR(it, ans) cout << *it << " ";
    }

    cout << endl;

	return 0;
}