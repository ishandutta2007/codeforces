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
#define taskname "problem_b"

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;

char buf[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%s", buf);
	int n = strlen(buf);
	
	vector <char> lst;
	for (int i = 0; i < n; i++) {
		if (!lst.empty() && lst.back() == buf[i])
			lst.pop_back();
		else
			lst.pb(buf[i]);
	}

	if (lst.empty())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}