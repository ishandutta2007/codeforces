#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main(){
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int x = 0;
	for (int i = n - 1; i >= 0; i--){
		int t = s[i] - 'a';
		if (i == n - 1) t = t + x + 1; else t = t + x;
		x = t / 26;
		s[i] = 'a' + t % 26;			
	}
	if (x || s >= t) puts("No such string");
	else cout << s << endl;
}