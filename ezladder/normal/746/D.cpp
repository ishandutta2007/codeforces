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

int n, k, a, b;

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
	cin >> n >> k >> a >> b;
	if (a > b) {
		int ost = a - b;
		string ans = "";
		for (int i = 0; i < b; i++) {
			int now = min(ost, k - 1);
			ost -= now;
			for (int j = 0; j < now + 1; j++)
				ans += 'G';
			ans += 'B';
		}
		if (ost > k)	
			cout << "NO", exit(0);
		cout << ans;
		for (int i = 0; i < ost; i++)
			cout << 'G';
	} else {
		int ost = b - a;
		string ans = "";
		for (int i = 0; i < a; i++) {
			int now = min(ost, k - 1);
			ost -= now;
			for (int j = 0; j < now + 1; j++)
				ans += 'B';
			ans += 'G';
		}
		if (ost > k)
			cout << "NO", exit(0);
		cout << ans;
		for (int i = 0; i < ost; i++)
			cout << 'B';

	}
}