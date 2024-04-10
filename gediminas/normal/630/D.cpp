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
0
*/
/*input
1
*/
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
	cout << (n +1)*n*3 + 1;
}