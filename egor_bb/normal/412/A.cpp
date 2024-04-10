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
	LL n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	if (n-k > k-1){
		for (int i=k; i>1; i--){
			cout << "LEFT" << '\n';
		}
		for (int i=0; i<n-1; i++){
			cout << "PRINT " << s[i] << '\n' << "RIGHT" << '\n';
		}
		cout << "PRINT " << s[n-1];
	} else {
		for (int i=k; i<n; i++){
			cout << "RIGHT" << '\n';
		}
		for (int i=n-1; i>0; i--){
			cout << "PRINT " << s[i] << '\n' << "LEFT" << '\n';
		}
		cout << "PRINT " << s[0];
	}
	
}