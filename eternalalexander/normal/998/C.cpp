#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long x, y;
int n, t, cnt, a;
char s[400000];

int main() {
	cnt=0; t=-1;
	cin >> n >> x >> y;
	cin >> s;
	for (int i=1;i<=n;++i) {
		a=s[i-1]-'0';
		//cout << a << endl;
		if (a==0&&a!=t) {
			cnt++;
		}t=a;
	} if (cnt==0) cout<<0;
	else cout << min((long long)(cnt-1)*x+y, (long long)cnt*y);
	return 0;
}