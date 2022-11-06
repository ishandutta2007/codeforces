#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
inline int read(void){
	int x = 0, c = 0, f = 1;
	for (;c<'0'||c>'9';c=getchar())f=c!='-';
	for (;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
int main() {
	int a = read(), b = read();
	int cnt = 1;
	while (a >= 0 && b >= 0) {
		if (cnt&1) a -= cnt;
		else b -= cnt;
		cnt++;
	}
	if (cnt & 1) puts("Valera");
	else puts("Vladik");
}