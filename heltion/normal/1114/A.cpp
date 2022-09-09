#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
auto no = [](){cout << "NO"; exit(0);};
auto read = [](){int x; cin >> x; return x;};
int main(){
	ios::sync_with_stdio(false);
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	if(a < x) no();
	if(a + b < x + y) no();
	if(a + b + c < x + y + z) no();
	cout << "YES";
}