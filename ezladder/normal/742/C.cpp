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

ll n;
ll to[107];
ll kek[107];
bool was[107];
ll mi = -1;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll get(ll a, ll b) {
	return a * b / gcd(a, b);
}

void dfs(ll v, ll len) {
	was[v] = 1;	
	if (was[to[v]]) {
		len++;
		if (mi == -1) {
			if (len % 2 == 0)
				mi = len / 2;
			else
				mi = len;
		} else {
			if (len % 2 == 0) {
				mi = get(mi, len / 2);
			} else {
				mi = get(mi, len);
			}
		}
	} else {
		dfs(to[v], len + 1);
	}
}

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
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> to[i], to[i]--, kek[to[i]]++;
	for (int i = 0; i < n; i++)
		if (kek[i] != 1)
			cout << -1, exit(0);
	for (int i = 0; i < n; i++)
		if (!was[i])
			dfs(i, 0);
	cout << mi;
}