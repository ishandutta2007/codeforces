#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=111;
#endif

int xx1, xx2, yy1, yy2;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> xx1 >> yy1 >> xx2 >> yy2;
	if (xx1==xx2) cout << xx1+(yy1-yy2) << ' ' << yy1 << ' ' << xx1+(yy1-yy2) << ' ' << yy2 << ' ' ;
	else if (yy1==yy2) cout << xx1 << ' ' << yy1+(xx1-xx2) << ' ' << xx2 << ' ' << yy1+(xx1-xx2) << ' ' ;
	else if (abs(xx1-xx2)==abs(yy1-yy2)) cout << xx1 << ' ' << yy2 << ' ' << xx2 << ' ' << yy1;
	else cout << -1;
	return 0;
}