#include <iostream>
using namespace std;
int main(){
	int t, n, a[150000], min, ans; scanf("%d", &t); for(int l=1; l<=t; l++) {
	ans=0; scanf("%d", &n); for(int i=0; i<n; i++) scanf("%d", &a[i]); min=a[n-1];
	for(int i=n-1; i>=0; i--) {
		if (a[i]>min) ans++; else min=a[i];
	}
	printf("%d \n", ans);
}}