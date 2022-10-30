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
vector < vector <int> > mass;

int SQR (){
	LL ans = 0, t = 0;
	for (int i=0; i<n; i++){
		t = 0;
		for (int j=0; j<n; j++){
			t += mass[i][j] * mass[j][i];
			t = t & 1;
		}
		ans += t;
		ans = ans & 1;
	}
	return ans;
}

int main (){
	int m;
	scanf ("%d", &n);
	mass.resize (n);
	for (int i=0; i<n; i++){
		mass[i].resize (n);
		for (int j=0; j<n; j++) scanf ("%d", &mass[i][j]);;
	}
	scanf ("%d", &m);
	int t;
	int q = -1, f = 0;
	q = SQR();
	for (int i=0; i<m; i++){
		scanf ("%d", &t);
		if (t==3){
			q += f;
			q = q & 1;
			cout << q;
			f = 0;
		}
		if (t==2){
			int k;
			scanf ("%d", &k);
			f++;
		}
		if (t==1){
			int k;
			scanf ("%d", &k);
			f++;
		}
	}
}