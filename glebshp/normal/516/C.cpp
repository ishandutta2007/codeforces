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
const int rms = (1 << 19) - 1;
const int hrms = rms / 2;
const int size = 250 * 1000 + 100;
const long long inf = (long long) 1e18;
const int ssize = 1000;

long long hg[size], d[size];
long long val1[size], val2[size];
long long dist[size];

pair <int, int> rmq1[rms + 1];
pair <int, int> rmq2[rms + 1];

bool comp1(int i, int j) {
	return val1[i] < val1[j];
}

bool comp2(int i, int j) {
	return val2[i] < val2[j];
}

int hlen;
int h[ssize];

pair <int, int> joinpairs1(pair <int, int> p1, pair <int, int> p2) {
	hlen = 0;
	h[hlen++] = p1.fs;
	h[hlen++] = p1.sc;
	h[hlen++] = p2.fs;
	h[hlen++] = p2.sc;

	sort(h, h + hlen, comp1);

	return mp(h[hlen - 1], h[hlen - 2]);
}

pair <int, int> joinpairs2(pair <int, int> p1, pair <int, int> p2) {
	hlen = 0;
	h[hlen++] = p1.fs;
	h[hlen++] = p1.sc;
	h[hlen++] = p2.fs;
	h[hlen++] = p2.sc;

	sort(h, h + hlen, comp2);

	return mp(h[hlen - 1], h[hlen - 2]);
}

long long trypair(int f, int s) {
	if (f == s)
		return -inf;
	return val1[f] + val2[s];
}

void rss1(int v, int lb, int rb, int i, int j) {
	if (lb > j || rb < i)
		return;
	if (lb >= i && rb <= j) {
		h[hlen++] = rmq1[v].fs;
		h[hlen++] = rmq1[v].sc;
		return;
	}
	rss1(v * 2, lb, (lb + rb) / 2, i, j);
	rss1(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j);
}

void rss2(int v, int lb, int rb, int i, int j) {
	if (lb > j || rb < i)
		return;
	if (lb >= i && rb <= j) {
		h[hlen++] = rmq2[v].fs;
		h[hlen++] = rmq2[v].sc;
		return;
	}
	rss2(v * 2, lb, (lb + rb) / 2, i, j);
	rss2(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j);
}



pair <int, int> getbest1(int a, int b) {
	hlen = 0;
	rss1(1, 1, hrms + 1, a, b);

	sort(h, h + hlen, comp1);

	return mp(h[hlen - 1], h[hlen - 2]);
}

pair <int, int> getbest2(int a, int b) {
	hlen = 0;
	rss2(1, 1, hrms + 1, a, b);

	sort(h, h + hlen, comp2);

	return mp(h[hlen - 1], h[hlen - 2]);
}

int n, m;

int main() {
/*
    freopen("input.txt", "w", stdout);
    int n = 100 * 1000;
    int m = 100 * 1000;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    	printf("%d ", rand() % (1000 * 1000 * 1000) + 1);
   	printf("\n");
    for (int i = 0; i < n; i++) {
		printf("%d ", rand() % (1000 * 1000 * 1000) + 1);
    }
   	printf("\n");
   	for (int i = 0; i < m; i++) {
   	    int tg = rand() % n;
   	    int h = tg + rand() % (n - 2);
   	    h %= n;
   		printf("%d %d\n", tg + 1, h + 1);
   	}
   	return 0;
*/    
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
    	scanf("%I64d", &d[i]);
    }
    for (int i = 0; i < n; i++) {
    	scanf("%I64d", &hg[i]);
    }
    for (int i = n; i < 2 * n; i++) {
    	d[i] = d[i - n];
    	hg[i] = hg[i - n];
    }

   	dist[0] = 0;
   	for (int i = 1; i < 2 * n; i++) {
   		dist[i] = dist[i - 1] + d[i - 1];
   	}
   	for (int i = 0; i <= rms; i++) {
   		rmq1[i] = mp(2 * n, 2 * n);
   		rmq2[i] = mp(2 * n, 2 * n);
   	}
   	val1[2 * n] = -inf;
   	val2[2 * n] = -inf;
   	for (int i = 0; i < 2 * n; i++) {
   		val1[i] = 2 * hg[i] + dist[i];
   		val2[i] = 2 * hg[i] - dist[i];

   		rmq1[i + hrms + 1] = mp(i, 2 * n);
   		rmq2[i + hrms + 1] = mp(i, 2 * n);
   	}

   	for (int i = hrms; i > 0; i--) {
   		rmq1[i] = joinpairs1(rmq1[i * 2], rmq1[i * 2 + 1]);
   		rmq2[i] = joinpairs2(rmq2[i * 2], rmq2[i * 2 + 1]);
   	}

   	for (int i = 0; i < m; i++) {
   		int a, b;
   		scanf("%d%d", &a, &b);
   		if (b < a)
   			b += n;
   		int c = a + n - 1;
  		pair <int, int> p1 = getbest1(b + 1, c);
   		pair <int, int> p2 = getbest2(b + 1, c);

   		printf("%I64d\n", max(max(trypair(p1.fs, p2.fs), trypair(p1.fs, p2.sc)), max(trypair(p1.sc, p2.fs), trypair(p1.sc, p2.sc))));
   	}

//   	cerr << (clock() + 0.0) / CLOCKS_PER_SEC << endl;

    return 0;
}