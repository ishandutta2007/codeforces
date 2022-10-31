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
#include <functional>

#define pb push_back
#define mp make_pair

const int MOD=1e9+7;

using namespace std;

int n, a, p[1111111];
long long b[3000000];
vector<pair<int, int> > ans;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a), b[a]++;
	for (int i=0; i<=20; i++) for (int j=0; j<1111111; j++) if (!(j&(1<<i))) b[j]=b[j^(1<<i)]+b[j];
	for (int i=0, b=1; i<1111111; i++, b=(b*2)%MOD) p[i]=b;
	for (int i=0; i<1111111; i++) b[i]=p[b[i]]-1;
	for (int i=20; i>=0; i--) for (int j=0; j<(1<<i); j++) b[j]=(b[j]-b[j^(1<<i)]+MOD)%MOD;
	cout << b[0];
	return 0;
}