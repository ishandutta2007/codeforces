#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "problem_a"

const double pi = acos(-1.0);
int cnt[26];

bool check(int c, int n) {
	int need = 0;
	for (int i = 0; i < 26; i++)
		need += (cnt[i] + c - 1) / c;
	return need <= n; 
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	string str;
	cin >> str;
	int n;
	cin >> n;

	for (int i = 0; i < (int) str.size(); i++)
		cnt[str[i] - 'a']++;
	if (!check(str.size(), n)) {
		cout << -1 << endl;
		return 0;
	}
	int lb = 1;
	int rb = str.size();
	while (lb < rb) {
		int mid = (lb + rb) / 2;
		if (check(mid, n))
			rb = mid;
		else
			lb = mid + 1;
	}

	cout << lb << endl;
	int c = 0;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < (cnt[i] + lb - 1) / lb; j++) {
			cout << char('a' + i);
			c++;
		}
	while (c < n) {
		cout << 'a';
		c++;
	}
	cout << endl;


	return 0;
}