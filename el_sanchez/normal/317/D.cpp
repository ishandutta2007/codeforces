#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 40;
const int MAXK = 100500;

ll n, nn, result;
int much;
int a[MAXN], used[MAXK + 1];

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;

a[1]=1;
a[2]=2;
a[3]=1;
a[4]=4;
a[5]=3;
a[6]=2;
a[7]=1;
a[8]=5;
a[9]=6;
a[10]=2;
a[11]=1;
a[12]=8;
a[13]=7;
a[14]=5;
a[15]=9;
a[16]=8;
a[17]=7;
a[18]=3;
a[19]=4;
a[20]=7;
a[21]=4;
a[22]=2;
a[23]=1;
a[24]=10;
a[25]=9;
a[26]=3;
a[27]=6;
a[28]=11;
a[29]=12;
a[30]=14;

	result = 1;
	nn = min(n, 1ll * MAXK);
	much = n - nn;
	for (ll i = 2; i <= nn; i++) {
		if (used[i])
			continue;

		int gr = 0;
		ll j = i;
		while (j <= nn) {
			gr++;
			used[j] = 1;
			j *= i;
		}
		while (j <= n) {
			gr++;
			much--;
			j *= i;
		}
		result ^= a[gr];
	}

	much = max(much, 0);
	if (much & 1)
		result ^= 1;	

	cout << (result == 0 ? "Petya" : "Vasya");

	return 0;
}