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
  
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sort stable_sort
#define problem "tax"
 
using namespace std;
 
typedef pair <int, int> pii;
typedef unsigned  long long ll;
typedef pair <ll, ll> pll;
 
const int INF = int(1e9 + 7);
const ll INFll = ll(1e18 + 7);
const double Pi =  3.1415926535897932384626433832795028841971;

int a[100005], n, t, used[100005], k = 1;

int main(){
	cin >> n >> t;
	for (int i = 1; i <= n - 1; i++){
		cin >> a[i];
	}
	while (!used[k]){
		if (k == t){
			cout << "YES";
			return 0;
		}
		used[k] = 1;
		k = a[k] + k;
	}
	cout << "NO";

    return 0;
}