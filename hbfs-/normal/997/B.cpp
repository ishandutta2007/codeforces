#include <bits/stdc++.h>
using namespace std;
const int F[] = {0,4,10,20,35,56,83,116,155,198,244,292,341,390,439};
int n;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd();
	if (n >= 14) {
		cout << 49LL*(n-14)+1LL*F[14] << endl;
	} else {
		cout << F[n] << endl;
	}
	return 0;
}