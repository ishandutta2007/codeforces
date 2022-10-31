#include <cstdio>
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

#define mod 1000000007

string a, b;

int main() {
	cin >> a >> b;
	int ca, cb;
	for (int i=0; i<(int)a.length(); i++) if (a[i]=='1') ca++;
	for (int i=0; i<(int)b.length(); i++) if (b[i]=='1') cb++;
	if (cb<=((ca+1)/2)*2) cout << "YES";
	else cout << "NO";
	return 0;
}