#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const double eps = 1e-9;

int main(){

	int x = nxt(), y = nxt();
	if (y > x){
		puts("-1");
		return 0;
	}

	cout << setprecision(10) << fixed;
	cout << 0.5 * min((x + y) * 1.0 / ((x + y) / (2 * y)), (x - y) * 1.0 / ((x - y) / (2 * y))) << "\n";

	return 0;
}