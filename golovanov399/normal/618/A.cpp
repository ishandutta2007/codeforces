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

int main(){

	int n = nxt();
	for (int i = (1 << 30); i > 0; i >>= 1){
		if (n & i){
			cout << __builtin_ctz(i) + 1 << " ";
		}
	}
	cout << "\n";

	return 0;
}