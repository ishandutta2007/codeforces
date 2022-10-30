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
	LL ans = 0;
	LL a1, a2, a3, a4;
	string s;
	cin >> a1 >> a2 >> a3 >> a4;
	cin >> s;
	for (int i=0; i<s.size(); i++){
		if (s[i]=='1') ans+=a1;
		if (s[i]=='2') ans+=a2;
		if (s[i]=='3') ans+=a3;
		if (s[i]=='4') ans+=a4;
	}
	cout << ans;
}