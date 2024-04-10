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
const int MAXN = 111;

int n, m, id;
int cities[MAXN], votes[MAXN], curVotes[MAXN];         

int main() {
	
	scanf("%d %d\n", &n, &m);         
	forn(i, m) {
		forn(i, n) {
			scanf("%d", &curVotes[i]);
			votes[i] += curVotes[i];
		}
		
		id = 0;
		forab(i, 1, n)
			if (curVotes[i] > curVotes[id])
				id = i;
		cities[id]++;
	}
	
	id = 0;
	forab(i, 1, n)
		if (cities[i] > cities[id])
			id = i;
	cout << id + 1;
	
	return 0;
}