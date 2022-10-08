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
const int size = 1000 * 1000;

bool used[size];
int pleft[size];
int pright[size];
int a[size];
int n;

int getleft(int v) {
	if (pleft[v] == -1)
		return -1;
	if (used[pleft[v]])
		pleft[v] = getleft(pleft[v]);
	return pleft[v];
}

int getright(int v) {
	if (pright[v] == -1)
		return -1;
	if (used[pright[v]])
		pright[v] = getright(pright[v]);
	return pright[v];
}

bool islocmin(int v) {
	if (v == -1 || used[v])
		return false;
	int lft = getleft(v);
	int rgt = getright(v);
	return (lft != -1 && rgt != -1 && a[lft] >= a[v] && a[rgt] >= a[v]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    }
    pleft[0] = -1;
    for (int i = 1; i < n; i++)
    	pleft[i] = i - 1;
    pright[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    	pright[i] = i + 1;
    set <int> lmin;
    for (int i = 1; i < n - 1; i++)
    	if (a[i - 1] >= a[i] && a[i + 1] >= a[i])
    		lmin.insert(i);
    long long ans = 0;
    while (!lmin.empty()) {
    	int ps = *lmin.begin();
    	lmin.erase(lmin.begin());
    	if (!islocmin(ps))
    		continue;

    	used[ps] = true;
    	int lft = getleft(ps);
    	int rgt = getright(ps);
    	if (lft != -1 && rgt != -1) 
    		ans += min(a[lft], a[rgt]);
    	if (islocmin(lft))
    		lmin.insert(lft);
       	if (islocmin(rgt))
       		lmin.insert(rgt);
    }

    vector <int> allrem;
    for (int i = 0; i < n; i++)
    	if (!used[i])
    		allrem.pb(a[i]);
    sort(allrem.rbegin(), allrem.rend());
    for (int i = 0; i < (int) allrem.size() - 2; i++)
    	ans += allrem[i + 2];

    cout << ans << endl;

    return 0;
}