#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
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
int a[maxn];
int cnt[30];
vi nr;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < 30; j++)
			if (a[i] & (1 << j)) cnt[j]++;
	}
	int cpl = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		int r = 0;
		for (int j = 0; j < 30; j++)
			if (a[i] & (1 << j))
				if (cnt[j] == 1) r += (1 << j);
		if (r > cur) {
			cur = r;
			cpl = i;
		}
	}
	for (int j = 0; j < n; j++)
		printf("%d ", a[(j + cpl) % n]);
	return 0;
}