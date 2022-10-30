#pragma comment (linker, "/STACK:100000000")

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>
#define INF 1e18

#define LL long long
#define mp make_pair
#define pb push_back
#define ULL unsigned long long

using namespace std;
	

int main (){
	int n, m;
	cin >> n >> m;
	vector <int> mass;
	mass.resize (m);
	for (int i=0; i<m; i++) cin >> mass[i];
	sort (mass.begin(), mass.end());
	int ans = 10000000;
	for (int i=0; i<m-n+1; i++){
		if (mass[i+n-1]-mass[i] < ans) ans = mass[i+n-1]-mass[i];
	}
	cout << ans;
}