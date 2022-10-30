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
	int x1, x2, y1, y2, x3, x4, y3, y4;
	 cin >> x1 >> y1 >> x2 >> y2;
	 if (x1 == x2){
		 cout << x1 + abs(y2 - y1) << " " << y1 << " " << x1 + abs(y2 - y1) << " " << y2; 
	 } else if (y1 == y2){
		 cout << x1 << " " << y1 + abs(x1 - x2) << " " << x2 << " " << y2 + abs(x1 - x2); 
	 } else {
		 if (abs(x1 - x2) != abs(y1 - y2)) cout << -1;
		 else cout << x1 << " " << y2 << " " << x2 << " " << y1;
	 }


}