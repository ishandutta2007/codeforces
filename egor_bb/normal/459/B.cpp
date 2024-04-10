
 #pragma comment (linker, "/STACK:100000000")

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>
#define INF 1e9
#define LL long long
#define mp make_pair
#define pb push_back
#define ULL unsigned long long

using namespace std;
	


int main (){
	int n, b[200003];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> b[i];
	int mn = INF + 10, mx = -INF - 10, cn = 0, cx = 0;
	for (int i = 0; i < n; i++){
		if (b[i] < mn){
			mn = b[i];
			cn = 1;
		} else if (b[i] == mn) cn++;
		if (b[i] > mx){
			mx = b[i];
			cx = 1;
		} else if (b[i] == mx) cx++;

	}
    if (mx == mn) cout << "0 " << 1ll * n*(n-1)/2;
	else cout << mx - mn << " " << 1ll * cx * cn;
}