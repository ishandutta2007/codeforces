#include <bits/stdc++.h>
#define N 1000500
#define tp 100000
using namespace std;
typedef long long LL;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

void solve() {
	int a = rd(), b = rd(), flag = 1;
	int ta = a, tb = b;
	LL s = 1LL * a * b;
	int k = round( pow(s, 1.0/3.0) );
	if (1LL * k * k * k != s) flag = 0;
	if (ta % k != 0 || tb % k != 0) flag = 0;
	puts(flag?"Yes":"No");
}

int main() {
    for (int T=rd();T;T--) solve();
	return 0;
}