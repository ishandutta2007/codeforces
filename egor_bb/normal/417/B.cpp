#pragma comment (linker, "/STACK:10000000000")
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
 

int a[100005], n;

int main()
{
	cin >> n;
	for (int i = 0; i < 100005; i++) a[i] = -1;
	for (int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		if (a[y] < x - 1){
			cout << "NO";
			return 0;
		}
		a[y] = max(x, a[y]);
	}
	cout << "YES";
}