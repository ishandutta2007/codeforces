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
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

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

int n;
int a[1000007];
int cont[1000007];

int main() {
    cin >> n;
    REP(i, n) {
        scanf("%d", &a[i]);
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
        VI res;
        int now = 1;
        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                res.PB(j);
                while (a[i] % j == 0) {
                    a[i] /= j;
                }
                now = max(now, cont[j] + 1);
            }
        }
        if (a[i] != 1) {
            res.PB(a[i]);
            now = max(now, cont[a[i]] + 1);
        }
        TR(it, res) {
            cont[*it] = max(cont[*it], now);
        }

        ans = max(ans, now);
    }
    cout << ans << endl;
	return 0;
}