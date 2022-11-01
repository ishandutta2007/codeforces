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

int arr[2222222];
int pos[2222222];

int x[2222222];
int q[2222222];
int ans[2222222];
int n, m;
int top;

void dfs(int aim) {
	if (top <= 0) return;
	if (arr[top - 1] == aim) return;
	int t = arr[--top];
	int p = pos[top];
	ans[p] = -ans[p];
	dfs(t);
	--top;
	dfs(aim);
}

int main() {
	cin >> n;
	REP(i, n) scanf("%d", &x[i]);
	cin >> m;
	REP(i, m) {
		scanf("%d", &q[i]);
		x[q[i] - 1] = -abs(x[q[i] - 1]);
	}
	REP(i, n) ans[i] = x[i];
	bool ok = true;
	REP(i, n) {
		if (x[i] > 0) {
			arr[top++] = x[i];
			pos[top - 1] = i;
		} else {
			dfs(abs(x[i]));
			if (top <= 0) {
				ok = false;
				break;
			}
			assert(arr[top - 1] == abs(x[i]));
			--top;
		}
	}

	while (ok && top > 0) {
		int now = arr[top - 1];
		int t = pos[top - 1];
		ans[t] = -ans[t];
		--top;
		dfs(now);
		if (top <= 0) {
			ok = false;
			break;
		}
		assert(arr[top - 1] == abs(now));
		--top;
	}

	if (!ok) cout << "NO\n";
	else {
		cout << "YES\n";
		REP(i, n) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}