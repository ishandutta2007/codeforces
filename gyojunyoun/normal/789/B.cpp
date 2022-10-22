#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define MAXN (100005)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline ll myabs(const ll& n) { return n < 0 ? -n : n; }

set<ll> Q;
ll A[MAXN];
ll b1, q, l;
int N;

int main() {
	cin >> b1 >> q >> l >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	if(myabs(b1) > l) { puts("0"); return 0; }
	if(b1 == 0) {
		bool flag = false;
		for(int i = 0; i < N; i++) if(0 == A[i]) flag = true;
		if(flag) puts("0");
		else puts("inf");
		return 0;
	}
	if(q == 0) {
		bool flag1 = false, flag2 = false;
		for(int i = 0; i < N; i++) {
			if(0 == A[i]) flag2 = true;
			if(b1 == A[i]) flag1 = true;
		}
		if(myabs(b1) > l) flag1 = true;
		if(flag1 && flag2) puts("0");
		else if(!flag1 && flag2) puts("1");
		else if(flag1 && !flag2) puts("inf");
		else puts("inf");
		return 0;
	}
	if(q == 1) {
		bool flag = false;
		for(int i = 0; i < N; i++) if(b1 == A[i]) flag = true;
		if(myabs(b1) > l) flag = true;
		if(flag) puts("0");
		else puts("inf");
		return 0;
	}
	if(q == -1) {
		bool flag1 = false, flag2 = false;
		for(int i = 0; i < N; i++) {
			if(b1 == A[i]) flag1 = true;
			if(-b1 == A[i]) flag2 = true;
		}
		if(myabs(b1) > l) flag1 = flag2 = true;
		if(flag1 && flag2) puts("0");
		else if(flag1 && !flag2) puts("inf");
		else if(!flag1 && flag2) puts("inf");
		else puts("inf");
		return 0;
	}
	
	for(ll now = b1;;) {
		if(myabs(now) > l) break;
		Q.insert(now);
		now *= q;
	}
	for(int i = 0; i < N; i++) Q.erase(A[i]);
	printf("%d\n", sz(Q));
	return 0;
}