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
	int ans = 109000;
	vector <vector <int> > mass, m, table;
	vector <vector <vector <int> > > t;

void go (int k, int w){
	if (k+1 >= ans) return;
	for (int i=w; i<10; i++){
			t[k] = mass;
			for (int j=0; j<n; j++){
				if (m[j][0] == i){
					for (int q=0; q<5; q++){
						mass[j][q] = 0;
					}
					mass[j][i] = 1;
				} else if (m[j][1] == i){
					for (int q=5; q<10; q++){
						mass[j][q] = 0;
					}
					mass[j][i] = 1;
				} else {
					mass[j][i] = 0;
				}
			}
			bool flag = true;
			int sum;
			for (int j=0; j<n; j++){
				sum = 0;
				for (int q=0; q<5; q++){
					if (mass[j][q]==1){
						for (int e = 5; e<10; e++){
							if (mass[j][e]==1 && table[q][e-5]==1) sum++;
						}
					}
				}
				if (sum!=1){
					flag = false;
					break;
				}
			}
			if (flag){
				if (ans > k+1){
					ans = k+1;
				}
			} else {
				go (k+1, i+1);
			}
			mass = t[k];
	}
}

int main (){
	t.resize (15);
	table.resize (5);
	for (int i=0; i<5; i++) table[i].resize (5);
	cin >> n;
	mass.resize (n);
	for (int i=0; i<n; i++) mass[i].resize (10);
	m.resize (n);
	int q;
	char t;
	for (int i =0; i<n; i++){
		cin >> t >> q;
		if (t=='R') {
			m[i].pb (0);
			table[0][q-1] = 1;
		}
		if (t=='G'){
			m[i].pb (1);
			table[1][q-1] = 1;
		}
		if (t=='B') {
			m[i].pb (2);
			table[2][q-1] = 1;
		}
		if (t=='Y'){
			m[i].pb (3);
			table[3][q-1] = 1;
		}
		if (t=='W'){
			m[i].pb (4);
			table[4][q-1] = 1;
		}
		m[i].pb (q+4);
		for (int j=0; j<n; j++){
			mass[j][q+4] = 1;
			if (t=='R') mass[j][0] = 1;
			if (t=='G') mass[j][1] = 1;
			if (t=='B') mass[j][2] = 1;
			if (t=='Y') mass[j][3] = 1;
			if (t=='W') mass[j][4] = 1;
		}
	}
	bool flag = true;
			int sum =0;
			for (int j=0; j<n; j++){
				sum = 0;
				for (int q=0; q<10; q++){
					sum+=mass[j][q];
				}
				if (sum!=2){
					flag = false;
					break;
				}
			}
	if (flag) cout << 0;
	else{
		go (0, 0);
		cout << ans;
	}
}