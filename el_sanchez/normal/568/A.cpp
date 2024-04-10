//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
*/
               
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 2000500;
    
int notP[MAXN], prime[MAXN], palin[MAXN];
int a[2];
ll p, q;
ll n[2], N;
string s, ss;

int main() {
	
	for (int i = 2; i < MAXN; i++) {
		if (!notP[i]) {
			prime[i] = 1;
			a[0]++;
			//cout << i << '\n';
			if (1ll * i * i >= MAXN)
				continue;
			for (int j = i * i; j < MAXN; j += i)
				notP[j] = 1;	
		}
	}
	
	//cout << a[0] << '\n';
	
	for (int i = 1; i < MAXN; i++) {
		s = "";
		int k = i;
		while (k > 0) {
			s += char('0' + k % 10);
			k /= 10;
		}
		ss = s;
		reverse(all(ss));
		if (s == ss) {
			//cerr << s << '\n';
			palin[i] = 1;
			a[1]++;
		}
	}
	
	cin >> p >> q;
	n[0] = n[1] = 0;
	for (int i = 1; i < MAXN; i++) {
		n[0] += prime[i];
		n[1] += palin[i];
		if (q * n[0] <= p * n[1])
			N = i;	
	}
	cout << N;
	
	//cout << a[1] << '\n';
	
	return 0;
}