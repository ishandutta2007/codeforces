#pragma comment (linker, "/STACK:100000000000")

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
#define INFll (1e17 + 7)
#define sort stable_sort

using namespace std;




ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}

int n, k, a[100005];


int main(){
//	ifstream cin ("in.txt");
	cin >> n >> k;
	if (k & 1){
		a[0] = (k + 1) / 2;
		for (int i = 1; i <= k; i++){
			if (i & 1) a[i] = a[i - 1] + i;
			else a[i] = a[i - 1] - i;
		}
		for (int i = k + 1; i < n; i++) a[i] = a[i - 1] + 1;
		
		for (int i = 0; i < n; i++) cout << a[i] << " ";
	}
	else {
		a[0] = (k + 2) / 2;
		for (int i = 1; i <= k; i++){
			if (i & 1) a[i] = a[i - 1] - i;
			else a[i] = a[i - 1] + i;
		}
		for (int i = k + 1; i < n; i++) a[i] = a[i - 1] + 1;
		
		for (int i = 0; i < n; i++) cout << a[i] << " ";
	}
	return 0;
}