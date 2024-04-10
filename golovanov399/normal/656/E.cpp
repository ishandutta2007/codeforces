#include <bits/stdc++.h>

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int a[11][11];

int in(int i, int j, int n){
	a[i][j] = nxt();
	i = i + (j + 1) / n;
	j = (j + 1) % n;
	return (i < n) ? in(i, j, n) : 0;
}

int rec(int i, int j, int k, int n){
	a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
	k++;
	j += k == n ? 1 : 0;
	k %= n;
	i += j == n ? 1 : 0;
	j %= n;
	return i < n ? rec(i, j, k, n) : 0;
}

int get_mx(int i, int n){
	return i == n ? 0 : max(*max_element(a[i], a[i] + n), get_mx(i + 1, n));
}

int main(){

	int n = nxt();
	in(0, 0, n);

	rec(0, 0, 0, n);

	cout << get_mx(0, n) << "\n";

	return 0;
}