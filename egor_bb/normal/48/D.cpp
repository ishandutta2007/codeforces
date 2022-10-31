#pragma comment (linker, "/STACK:10000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e18 + 7)
#define sort stable_sort

using namespace std;


int n, a[100005], num[100005], c[100005];

int main(){
	//ifstream in ("in.txt");
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		num[a[i]]++;
	}
	for (int i = 1; i < 100000; i++){
		if (num[i] < num[i + 1]){
			cout << -1;
			return 0;
		}
	}
	cout << num[1] << '\n';
	for (int i = 0; i < n; i++){
		cout << c[a[i]] + 1 << " ";
		c[a[i]]++;
	}

	return 0;
}