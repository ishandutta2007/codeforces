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
	int n, k, x;
	cin >> n >> k >> x;
	vector <pair <int, int> > mass;
	int p=0, c=-1, t;
	for (int i=0; i<n; i++){
		cin >> t;
		if (t==c) p++;
		else if (c != -1){
			mass.pb (mp (c, p));
			c = t;
			p=1;
		}
		else {
			c = t;
			p++;
		}
	}
	mass.pb (mp (c, p));
	int ansb = 0;
	for (int i=0; i<mass.size (); i++){
		int ans=0;
		if (mass[i].first == x && mass[i].second == 2){
			ans += mass[i].second;
			int p1 = i-1, p2 = i+1;
			while (p1>=0 && p2 < mass.size ()){
				if (mass[p1].first == mass[p2].first && mass[p1].second +mass[p2].second >= 3){
					ans += mass[p1].second +mass[p2].second;
					p1--;
					p2++;
				} else break;
			}
		}
		if (ans > ansb) ansb = ans;
	}
	cout << ansb;
}