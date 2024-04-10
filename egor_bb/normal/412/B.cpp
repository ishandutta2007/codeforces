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
#define INF 2000000000000000000

#define LL long long
#define mp make_pair
#define pb push_back
#define ULL unsigned long long

using namespace std;



int main (){
	LL n, k;
	cin >> n >> k;
	vector <int> mass;
	mass.resize (n);
	for (int i=0; i<n; i++) cin >> mass[i];
	sort(mass.begin(), mass.end());
	cout << mass[n-k];
	
}