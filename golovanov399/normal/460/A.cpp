#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

//	freopen("combo.in", "r", stdin);
//	freopen("combo.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int ans = 0;
	while (n > 0){
		ans++;
		n--;
		if (ans % m == 0) n++;
	}
	cout << ans << "\n";
	
	return 0;
}