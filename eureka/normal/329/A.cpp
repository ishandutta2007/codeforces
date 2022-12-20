#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;
const int N = 200;

int main(){
	int n;
	char ch[N][N];
	int a[N], b[N];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(a));
	cin >> n;
	for (int i=0; i<n; ++i) cin >> ch[i];
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j){
		if (ch[i][j] == '.'){
			a[i+1] = j+1;
			b[j+1] = i+1;
		}
	}
	bool fa = false, fb = false;
	for (int i=1; i<=n; ++i){
		if (a[i] == 0) fa = true;
		if (b[i] == 0) fb = true;
	}
	if (fa && fb) puts("-1");
	else if (fa) for (int i=1; i<=n; ++i) printf("%d %d\n", b[i], i);
	else for (int i=1; i<=n; ++i) printf("%d %d\n", i, a[i]);
	return 0;
}