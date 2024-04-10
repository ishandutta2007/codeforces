#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
int a[maxn];
bool v[maxn], w[maxn];
int main(){
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i += 1){
		scanf("%d", a + i);
		if(v[a[i]]){
			printf("0");
			return 0;
		}
		v[a[i]] = true;
	}
	for(int i = 0; i < n; i += 1)
		if(v[a[i] & x] && (a[i] & x) != a[i]){
			printf("1");
			return 0;
		}
	for(int i = 0; i < n; i += 1){
		if(w[a[i] & x]){
			printf("2");
			return 0;
		}
		w[a[i] & x] = true;
	}
	printf("-1");
	return 0;
}