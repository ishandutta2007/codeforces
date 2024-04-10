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
const int MAXN = 200100;

int n, m, k, L, R, current, upd;
string s;
char c;
set<pii> sL, sR;

void erasePair(pii p) {
	sL.erase(p);
	swap(p.X, p.Y);
	sR.erase(p);
}

void insertPair(pii p) {
	sL.insert(p);
	swap(p.X, p.Y);
	sR.insert(p);
}            

int main() {
	
	scanf("%d %d\n", &n, &m);
	cin >> s;
	sL.insert({INF, INF});
	sL.insert({-INF, -INF});
	sR.insert({INF, INF});
	sR.insert({-INF, -INF});	
	
	current = 0;
	L = -1;
	if (s[0] == '.')
		L = 0;
	forab(i, 1, s.size() + 1) {
		if (i == s.size() || s[i] != '.') {
			if (L != -1) {
				R = i - 1;
				
				insertPair({L, R});
								
				current += R - L;
				L = -1;
			}
		} else {
			if (L == -1)
				L = i;
		}
	}
	                   
	forn(i, m) {
		scanf("%d %c\n", &k, &c);
		k--;

		if (s[k] == '.') { //erase
			pii cR = *sR.lower_bound({k, -INF});
			pii cL = {cR.Y, cR.X};
			
			erasePair(cL);
			
			current -= cL.Y - cL.X;
			
			if (cL.X < k) {
				insertPair({cL.X, k - 1});  
				current += k - 1 - cL.X;	
			}

			if (k < cL.Y) {
				insertPair({k + 1, cL.Y});
                current += cL.Y - k - 1;	
			}						
		}
		
		s[k] = c;
		if (s[k] == '.') { //merge
			pii cL = *sL.lower_bound({k + 1, -INF});	
			pii cR = *sR.lower_bound({k - 1, -INF});
			swap(cR.X, cR.Y);
			
			int L = k, R = k;
			
			if (cL.X == k + 1) {
				R = cL.Y;
				erasePair(cL);
				current -= cL.Y - cL.X;
			}
			if (cR.Y == k - 1) {
				L = cR.X;
				erasePair(cR);
				current -= cR.Y - cR.X;
			}
			
			cL = {L, R};
			insertPair(cL);
			current += R - L;
		}
		
		printf("%d\n", current);
	}
	
	return 0;
}