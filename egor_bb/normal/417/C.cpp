#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>

#define LL long long
#define ULL unsigned long long

using namespace std;

int main (){

	int n, k;
	cin >> n >> k;
	if (k > n-1) {
		cout << -1;
		return 0;
	}
	vector < vector <int> > mass;
	vector < pair <int, int> > ans;
	mass.assign (n+1, vector <int> (n+1, 0));
	for (int i=1; i<=n; i++){
		mass[i][i]=1;
		int p=0;
		for (int j=1; j<=n; j++){
			if (p==k) break;
			if (mass[i][j%n+1]==0){
				ans.push_back (make_pair(i, j%n+1));
				mass[i][j%n+1]=1;
				mass[j%n+1][i]=1;
				p++;
			}
		}
		if (p!=k) {
			cout << -1;
			return 0;
		}
	}
	cout << n*k << '\n';
	for (int i=0; i<ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << '\n';
	}
}