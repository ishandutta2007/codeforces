#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int main(){
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int a = abs(x - y) * t1;
	int b = abs(x - z) * t2 + abs(x - y) * t2 + 3 * t3;
	printf(a >= b ? "YES" : "NO");
}