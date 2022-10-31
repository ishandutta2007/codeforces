#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=111111;
#else
const int maxn=111;
#endif

int c1[300000], c2[300000];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	string s1, s2;
	cin >> s1 >> s2;
	for (int i=(int)s1.length()-1, j=0; i>=0; i--, j++) c1[j]=s1[i]-'0';
	for (int i=(int)s2.length()-1, j=0; i>=0; i--, j++) c2[j]=s2[i]-'0';
	for (int i=150000; i>=0; i--) for (int j=i; c1[j]==c1[j+1]&&c1[j]==1; j+=2) c1[j]--, c1[j+1]--, c1[j+2]++;
	for (int i=150000; i>=0; i--) for (int j=i; c2[j]==c2[j+1]&&c2[j]==1; j+=2) c2[j]--, c2[j+1]--, c2[j+2]++;
	for (int i=150000; i>=0; i--) {
		if (c1[i]>c2[i]) {
			cout << '>';
			return 0;
		} else if (c1[i]<c2[i]) {
			cout << '<';
			return 0;
		}
	}
	cout << '=';
	return 0;
}