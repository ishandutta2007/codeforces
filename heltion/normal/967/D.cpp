#include<bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
int read(){
	int x = 0;
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

long long *c;
int main(){
	long long n = read(), x1 = read(), x2 = read();
	c = new long long [n + 1];
	long long *d = new long long [n + 1];
	for(int i = 1; i <= n; i += 1) c[i] = read();
	for(int i = 1; i <= n; i += 1) d[i] = i;
	sort(d + 1, d + n + 1, [](const int &a, const int &b) -> bool{return c[a] < c[b];});
	sort(c + 1, c + n + 1);
	long long *a = new long long[n + 1];
	long long *m = new long long[n + 1];
	for(int i = n; i >= 1; i -= 1) m[i] = a[i] = c[i] * (n - i + 1);
	for(int i = n - 1; i >= 1; i -= 1) m[i] = max(m[i], m[i + 1]);
	for(int k1 = 1; k1 <= n; k1 += 1){
		int pos = lower_bound(c + 1, c + n + 1, x1 % k1 == 0 ? x1 / k1 : x1 / k1 + 1) - c;
		if(pos + k1 <= n and x2 <= m[pos + k1]){
			int k2 = 0;
			for(int i = pos + k1; i <= n; i += 1) if(x2 <= a[i]){
				k2 = n - i + 1;
				break;
			}
			printf("Yes\n%d %d\n", k1, k2);
			for(int i = pos; i < pos + k1; i += 1) printf("%d ", d[i]); printf("\n");
			for(int i = n - k2 + 1; i <= n; i += 1) printf("%d ", d[i]); printf("\n");
			return 0;
		} 
	}
	for(int k1 = 1; k1 <= n; k1 += 1){
		int pos = lower_bound(c + 1, c + n + 1, x2 % k1 == 0 ? x2 / k1 : x2 / k1 + 1) - c;
		if(pos + k1 <= n and x1 <= m[pos + k1]){
			int k2 = 0;
			for(int i = pos + k1; i <= n; i += 1) if(x1 <= a[i]){
				k2 = n - i + 1;
				break;
			}
			printf("Yes\n%d %d\n", k2, k1);
			for(int i = n - k2 + 1; i <= n; i += 1) printf("%d ", d[i]); printf("\n");
			for(int i = pos; i < pos + k1; i += 1) printf("%d ", d[i]); printf("\n");
			return 0;
		} 
	}
	printf("No\n");
}

//long long?10 ^18int?10^9