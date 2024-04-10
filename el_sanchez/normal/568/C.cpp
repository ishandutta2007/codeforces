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
const int MAXN = 100500;
const int ALPH = 26;

string alph, s, ss;
int n, m, a, b, t1, t2, v1, v2, tmr;
int root, canGet[1111][1111];
int used[MAXN], setted[1111], isVowel[ALPH * 2], minChar[2], tried[2], variants[2];
char c1, c2;
vi g[MAXN];

void dfs(int v) {
	used[v] = tmr;
	canGet[root][v] = 1;
	for (auto w: g[v])
		if (used[w] != tmr)
			dfs(w); 
}

int main() {
	            
	cin >> alph;
	minChar[0] = minChar[1] = -1;
	forn(i, alph.size()) {
		isVowel[i] = (alph[i] == 'V');
		if (minChar[isVowel[i]] == -1)
			minChar[isVowel[i]] = i;
	}
	
	scanf("%d %d\n", &n, &m);
	forn(i, m) {
		scanf("%d %c %d %c\n", &a, &c1, &b, &c2);
		a--;
		b--;
		t1 = (c1 == 'C' ? 0 : 1);
		t2 = (c2 == 'C' ? 0 : 1);
		v1 = a * 2 + t1;
		v2 = b * 2 + t2;
		g[v1].pb(v2);  
		g[v2 ^ 1].pb(v1 ^ 1);  
		//cerr << "added " << v1 << ' ' << v2 << '\n';
		//cerr << "added " << (v2 ^ 1) << ' ' << (v1 ^ 1) << '\n';
	}
	
	cin >> s;
			
	forn(i, 2 * n) {
		root = i;
		tmr++;
		dfs(root);	
	}
	
	forn(i, n)
		if (canGet[i * 2][i * 2 + 1] && canGet[i * 2 + 1][i * 2]) {
			cout << -1;
			return 0;
		}
		
	for (int i = n - 1; i >= 0; i--) {
		//try to grow
		tried[0] = tried[1] = 0;
		
		char j = s[i];
		if (i < n - 1)
			j++;

		for (; j < 'a' + alph.size(); j++) {
			if (tried[isVowel[j - 'a']])
				continue;
			tried[isVowel[j - 'a']] = 1;
			//cerr << "try " << i << ' ' << j << '\n';	
			
			forn(k, n)
				setted[k] = isVowel[s[k] - 'a'];
		    
			setted[i] = isVowel[j - 'a'];
			for (int k = i + 1; k < n; k++) {
				setted[k] = -1;
				if (minChar[0] == -1)
					setted[k] = 1;
				else if (minChar[1] == -1)
					setted[k] = 0;
			}
			bool ok = 1;		
			/*
			for (int k = 0; k < n; k++)
				cerr << setted[k] << " \n"[k == n - 1];
			*/
			for (int k = 0; k < n; k++) {
				int oldValue = setted[k];
				
				variants[0] = variants[1] = 1;
				if (canGet[k * 2][k * 2 + 1])
					variants[0] = 0;
				if (canGet[k * 2 + 1][k * 2])
					variants[1] = 0;

				for (int t = 0; t < 2; t++)
					for (int v = 0; v < n; v++)
						if (k != v && setted[v] != -1) {
							if (canGet[k * 2 + t][v * 2 + 1 - setted[v]]) {
								//cerr << k * 2 + t << "->" << v * 2 + 1 - setted[v] << '\n';
								variants[t] = 0;
							}
						}

				//db(variants[0]);
				//db(variants[1]);		
				
				if (variants[0] && variants[1])
					setted[k] = (oldValue == -1 ? minChar[0] > minChar[1] : oldValue);
				else if (variants[0])
					setted[k] = 0;
				else if (variants[1])
					setted[k] = 1;
				else {
					ok = 0;
					break;
				}
				
				//cerr << "chosen " << k << ' ' << setted[k] << '\n';
				
				if (oldValue != -1 && setted[k] != oldValue) {
					ok = 0;
					break;
				}
			}
				
			if (ok) {
				s[i] = j;
				for (int k = i + 1; k < n; k++)
					s[k] = char('a' + minChar[setted[k]]);
				cout << s << '\n';
				
				return 0;
			}
		}
	}
	
	cout << -1;
	
	return 0;
}