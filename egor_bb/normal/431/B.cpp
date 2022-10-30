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
	

	
	LL ans = 0;
	vector < vector <LL> > matr;
	vector <int> w, used;
void count (int v){
	if (v==5){
		if (matr[w[0]][w[1]] + matr[w[1]][w[0]] + matr[w[2]][w[1]] + matr[w[1]][w[2]] + 2*(matr[w[2]][w[3]] + matr[w[3]][w[2]]) + 2*(matr[w[3]][w[4]] + matr[w[4]][w[3]])> ans){
			ans =matr[w[0]][w[1]] + matr[w[1]][w[0]] + matr[w[2]][w[1]] + matr[w[1]][w[2]] + 2*(matr[w[2]][w[3]] + matr[w[3]][w[2]]) + 2*(matr[w[3]][w[4]] + matr[w[4]][w[3]]);
		}
		return;
	}
	for (int i=0; i<5; i++){
		if (used[i]==0){
			used[i]=1;
			w[i] = v;
			count (v+1);
			used[i]=0;
		}
	}
}
int main (){
	matr.resize (5);
	used.resize (5, 0);
	w.resize (5, -1);
	for (int i=0; i<5; i++){
		matr[i].resize(5);
		for (int j=0; j<5; j++) cin >> matr[i][j];
	}
	count (0);
	cout << ans;
}