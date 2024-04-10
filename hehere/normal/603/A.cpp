#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <iomanip>
#include <string>
using std::string;
#include <algorithm>
#include <set>
using std::set; using std::multiset;
#include <map>
using std::map;
#include <bitset>
using std::bitset;

int readint() {
	int a = 0, po = 1; char c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') po = -1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return a * po;
}

bool chmax(int &a, int b) {
	return a < b ? a = b, true : false;
}
bool chmin(int &a, int b) {
	return a > b ? a = b, true : false;
}
const int maxN = 100000 + 233;
const int INF = 0x3f3f3f3f;
int n;
char s[maxN];
int f[maxN][3][2];
int max[3][2];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	cin >> (s + 1);
	for(int i = 1; i <= n; ++i) s[i] -= '0';
	memset(f, ~INF, sizeof(f));
	memset(max, ~INF, sizeof(max));
	int ans = 1;
	for(int i = 1; i <= n; ++i) {

        f[i][0][s[i]] = 0; f[i][2][s[i]] = 0;
		f[i][1][s[i]^1] = 0;

		chmax(f[i][0][s[i]], max[0][s[i]^1]);
		chmax(f[i][1][s[i]^1], max[0][s[i]]);
		chmax(f[i][1][s[i]^1], max[1][s[i]]);

//		 chmax(f[i][2][s[i]], max[0][s[i]^1]);
		chmax(f[i][2][s[i]], max[1][s[i]^1]);
		chmax(f[i][2][s[i]], max[2][s[i]^1]);

//        printf("f : %d %d %d\n", f[i][0][s[i]], f[i][1][s[i]^1], f[i][2][s[i]]);

		f[i][0][s[i]]++; f[i][2][s[i]]++;
		f[i][1][s[i]^1]++;

		for(int j = 0; j < 3; ++j)
            for(int k = 0; k < 2; ++k)
                chmax(max[j][k], f[i][j][k]);
//        printf("max : %d %d %d\n", max[0][s[i]], max[1][s[i]^1], max[2][s[i]]);
	}
	for(int j = 0; j < 3; ++j)
		for(int k = 0; k < 2; ++k) chmax(ans, max[j][k]);
	cout << ans << endl;
	return 0;
}