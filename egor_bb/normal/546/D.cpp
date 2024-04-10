#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "movetofront"

const int INF = int(1e9);
const int INFll = int(1e9) + 7;
const int SZ = 70;

using namespace std;

ll t, x, y, a[5000005], N = 5000001, ok[5000005], sum[5000005];

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	a[1] = 0;
	for (int i = 2; i < N; i++){
		if (ok[i] == 1) continue;
		a[i]++;
		if (!ok[i]) ok[i] = i;
		for (int j = 2 * i; j < N; j += i){
			ok[j] = 1;
			a[j]++;
		}
		if (i * ok[i] < N) ok[i * ok[i]] = ok[i];
	}
	for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + a[i];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d%d", &x, &y);
		printf("%d\n", sum[x] - sum[y]);
	}
}