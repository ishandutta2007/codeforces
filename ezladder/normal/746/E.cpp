#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

int n, m;
int a[2 * 100007];

map<int, int> kol;
vector<int> d1, d2;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int k1 = 0, k2 = 0;
	for (int i = 0; i < n; i++) {
		kol[a[i]]++;
		if (a[i] % 2 == 0)
			k1++;
		else
			k2++;
	}

	for (int i = 1; i <= min(m, 1000000); i++) {
		if (kol[i] == 0) {
			if (i % 2 == 0)
				d1.pub(i);
			else
				d2.pub(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (kol[a[i]] > 1) {
			if (k1 == k2) {
				if (a[i] % 2 == 0) {
					kol[a[i]]--;
					if (d1.size() == 0)
						printf("-1"), exit(0);
					if (a[i] % 2 == 1)
						k2--;
					else
						k1--;
					a[i] = d1.back();
					ans++;
					k1++;
					kol[d1.back()]++;
					d1.pop_back();
				} else {
					kol[a[i]]--;
					if (d2.size() == 0)
						printf("-1"), exit(0);
					if (a[i] % 2 == 1)
						k2--;
					else
						k1--;
					a[i] = d2.back();
					ans++;
					k2++;
					kol[d2.back()]++;
					d2.pop_back();
				}
				continue;
			}
			if (k1 > k2) {
				kol[a[i]]--;
				if (d2.size() == 0)
					printf("-1"), exit(0);
				if (a[i] % 2 == 1)
					k2--;
				else
					k1--;
				a[i] = d2.back();
				ans++;
				k2++;
				kol[d2.back()]++;
				d2.pop_back();
			} else {
				kol[a[i]]--;
				if (d1.size() == 0)
					printf("-1"), exit(0);
				if (a[i] % 2 == 1)
					k2--;
				else
					k1--;
				a[i] = d1.back();
				ans++;
				k1++;
				kol[d1.back()]++;
				d1.pop_back();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (k1 == k2)
			break;
		if (k1 > k2) {
			if (a[i] % 2 == 0) {
				k1--;
				if (d2.size() == 0)
					printf("-1"), exit(0);
				a[i] = d2.back();
				ans++;
				d2.pop_back();
				k2++;
			}
		} else {
			if (a[i] % 2 == 1) {
				k2--;
				if (d1.size() == 0)
					printf("-1"), exit(0);
				a[i] = d1.back();
				ans++;
				d1.pop_back();
				k1++;
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}