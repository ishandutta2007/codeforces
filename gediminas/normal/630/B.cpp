#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
1000 1000000
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	long double n, t;
	cin >> n >> t;
	cout << setprecision(10000) << exp(log(n) + t * log(1.000000011l));
}