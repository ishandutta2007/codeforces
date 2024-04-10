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


	ll a, b, ans = 0;

int main(){
//	ifstream in ("input.txt");
	cin >> a >> b;
	for (int k = 1; k <= a; k++){
		ll t, f;
		t = (b * k + 1);
		t = t % INF;
		f = (b - 1) * b / 2;
		f %= INF;
		t *= f;
		t = t % INF;
		ans += t;
		ans = ans % INF;
	}
	ans = ans % INF;
	cout << ans;
}