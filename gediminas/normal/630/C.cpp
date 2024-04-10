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
2
*/
/*input
3
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	long long n;
	cin >> n;
	cout << (1ll << (n+1)) - 2;
}