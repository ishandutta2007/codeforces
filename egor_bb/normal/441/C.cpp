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
	LL n, m, k;
	cin >> n >> m >> k;
	LL x = 1, y = 1, p = 1;
	for (int i=0; i<k-1; i++){
		cout << 2 << " ";
		cout << y << " " << x << " ";
		x+=p;
		if (x > m){
			x = m;
			y++;
			p = -1;
		}
		if (x == 0){
			x = 1;
			y++;
			p = 1;
		}
		cout << y <<  " " << x << " ";
		x+=p;
		if (x > m){
			x = m;
			y++;
			p = -1;
		}
		if (x == 0){
			x = 1;
			y++;
			p = 1;
		}
		cout << '\n';
	}
	cout << n*m-2*(k-1) <<  " ";
	for (int i=0; i<n*m-2*(k-1); i++){
		cout << y << " " << x << " ";
		x+=p;
		if (x > m){
			x = m;
			y++;
			p = -1;
		}
		if (x == 0){
			x = 1;
			y++;
			p = 1;
		}
	}
}