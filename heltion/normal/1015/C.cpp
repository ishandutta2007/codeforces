#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
long long del[maxn];
int main(){
	int n;
	long long m;
	scanf("%d %lld", &n, &m);
	for(int i = 0; i < n; i += 1){
		long long a, b;
		scanf("%lld %lld", &a, &b);
		del[i] = b - a;
		m -= a;
	}
	sort(del, del + n);
	for(int i = 0; i < n; i += 1){
		if(m >= 0){
			printf("%d", i);
			return 0;
		}
		m -= del[i];
	}
	printf("%d", m >= 0 ? n : -1);
}