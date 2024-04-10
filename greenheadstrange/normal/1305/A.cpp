#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n;
int b[maxn]; 
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) scanf("%d", &b[k]);
			sort(b, b + n);
			for (int k = 0; k < n; k++) printf("%d ", b[k]);
			printf("\n");
		}
	}
	return 0;
}