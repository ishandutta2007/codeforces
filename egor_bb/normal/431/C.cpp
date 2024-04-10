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
#define INF 1000000007

#define LL long long
#define mp make_pair
#define pb push_back
#define ULL unsigned long long

using namespace std;
	

	
	int n, k, d;
	vector < vector <LL> > matr;
	vector <int> done;
void go (int v){
	done[v] = 1;
	if (v==0){
		matr[v][0] = 1;
		matr[v][1] = 0;
		return;
	}
	for (int i=1; i<= min (k, v); i++){
		if (done[v-i]==0) go (v-i);
		if (i<d){
			matr[v][0] += matr[v-i][0];
			matr[v][1] += matr[v-i][1];
		} else {
			matr[v][1] += matr[v-i][0] + matr[v-i][1];
		}
		matr[v][0]%=INF;
		matr[v][1]%=INF;
	}
}

int main (){
	cin >> n >> k >> d;
	matr.resize (n+1, vector <LL> (2, 0));
	done.resize (n+1, 0);
	go(n);
	cout << matr[n][1];
}