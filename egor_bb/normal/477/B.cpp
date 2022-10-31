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

#define INF 1000000007
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back

using namespace std;



	ll n, k, a[10005][4], now = 1;
	
int main(){
//	ifstream in ("input.txt");
	cin >> n >> k;
	cout << (-1 + 6 * n) * k << '\n';
	for (int i = 0; i < n; i++){
		cout << now * k << " " << (now + 1) * k << " " << (now + 2) * k << " " << (now + 4) * k << '\n';
		now += 6;
	}
}