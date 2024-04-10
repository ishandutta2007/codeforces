#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x = 0;
	char c;
	bool pos = true;
	do{
		c = getchar();
		if(c == '-') pos = false;
	}while(c < '0' or c > '9');
	do{
		x = x * 10 + c - '0';
		c = getchar();
	}while(c >= '0'  and c <= '9');
	return pos ? x : - x;
}


int main(){
	int n = read(), q = read();
	long long *a = new long long[n];
	long long *s = new long long[n];
	for(int i = 0; i < n; i += 1) a[i] = read();
	s[0] = a[0];
	for(int i = 1; i < n; i += 1) s[i] = a[i] + s[i - 1];
	long long tmp = 0;
	for(int i = 0; i < q; i += 1){
		long long k = read();
		tmp += k;
		int pos = upper_bound(s, s + n, tmp) - s;
		if(pos < n) printf("%d\n", n - pos);
		else{
			printf("%d\n", n);
			tmp = 0;
		}
	}
}