#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>


using namespace std;


#define int long long
mt19937 rnd(rand());
int inf = 1e9;
int big_inf = 1e18;


int get(int x, int y){
	return (y + 1) * x * (x + 1) / 2 + (x + 1) * y * (y + 1) / 2;
}


signed main(){
	ios_base::sync_with_stdio(false);
	int ans = 0;

	int m, b;
	cin >> m >> b;
	int l;
	for (int x = 0; x <= 10000000 + 10; ++x){
		l = floor( b - ( x / ( m + 0.0) ) );
		
		if (l >= 0) ans = max(ans, get(x, l));
	}

	cout << ans;
	return 0;
}