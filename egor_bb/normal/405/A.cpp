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
	int n;
	vector <int> m, ans, m2;
	cin >> n;
	m.resize (n, 0);
	ans.resize (102, 0);
	m2.resize (n, 0);
	for (int i=0; i<n; i++){
		cin >> m[i];
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m[i]; j++){
			ans[j]++;
		}
	}
	for (int i=0; i<102; i++){
		for (int j=0; j<ans[i]; j++){
			m2[j]++;
		}
	}
	for (int i=n-1; i>=0; i--) cout << m2[i] << " ";
}