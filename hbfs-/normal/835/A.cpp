#include <bits/stdc++.h>
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int main() {
	int n,v1,v2,t1,t2;
	n = rd(), v1 = rd(), v2 = rd(), t1 = rd(), t2 = rd();
	int p1 = 2 * t1 + n * v1;
	int p2 = 2 * t2 + n * v2;
	if (p1 == p2) {
		puts("Friendship");
	} else {
		puts(p1<p2?"First":"Second");
	}
	return 0;
}