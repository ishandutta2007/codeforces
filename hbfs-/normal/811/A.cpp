#include <bits/stdc++.h>
#define N 1000500
using namespace std;
typedef long long LL;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int main() {
	int a = rd(), b = rd();
	for (int i=1;;i++) {
		if (i&1) a -= i; else b -= i;
		if (a<0 || b<0) {
			if (a<0) puts("Vladik");else puts("Valera");
			break;
		}
	}
	return 0;
}