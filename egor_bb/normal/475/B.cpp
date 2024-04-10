#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <string>

#define INF 1000000009
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back

using namespace std;

	int n, m;


int main(){
	cin >> n >> m;
	n--; m--;
	string s1, s2;
	cin >> s1 >> s2;
	bool flag = true;
	if (s1[0] == '<' && s2[0] == '^') flag = false;
	else if (s1[n] == '<' && s2[0] == 'v') flag = false;
	else if (s1[0] == '>' && s2[m] == '^') flag = false;
	else if (s1[n] == '>' && s2[m] == 'v') flag = false;
	if (flag) cout << "YES";
	else cout << "NO";
}