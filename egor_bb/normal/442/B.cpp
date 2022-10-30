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
	
	int n;


int main (){
	cout.precision (15);
	cin >> n;
	vector <double> mass;
	mass.resize (n);
	for (int i=0; i<n; i++) cin >> mass[i];
	sort (mass.begin(), mass.end());
	reverse (mass.begin(), mass.end());
	double ans = 0, t, t1;
	for (int i=0; i<n; i++){
		t = mass[0];
		t1 = 1-mass[0];
		for (int j=1; j<=i; j++){
			t*= (1-mass[j]);
			t+= t1*mass[j];
			t1*=(1-mass[j]);
		}
		if (t > ans) ans = t;
		for (int j=n-1; j>i; j--){
			t*= (1-mass[j]);
			t+= t1*mass[j];
			t1*=(1-mass[j]);
			if (t>ans) ans = t;
		}
	}
	t = mass[n-1];
	t1= 1-mass[n-1];
	if (t>ans) ans = t;
	for (int j=n-2; j>=0; j--){
t*= (1-mass[j]);
			t+= t1*mass[j];
			t1*=(1-mass[j]);
			if (t>ans) ans = t;
	}
	cout << ans ;

}