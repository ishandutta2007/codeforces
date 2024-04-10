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
	LL n, v;
	cin >> n >> v;
	vector <int> ans;
	int t, k;
	for (int i=0; i<n; i++){
		cin >> t;
		bool flag = false;
		for (int j=0; j<t; j++){
			cin >> k;
			if (k < v) flag = true;
		}
		if (flag) ans.pb (i+1);
	}
	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";
}