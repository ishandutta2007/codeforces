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
	string s, ans;
	cin >> n;
	cin >> s;
	ans = s;
	for (int i=1; i<n; i++){
		cin >> s;
		for (int j=0; j<s.size(); j++){
			if (s[j]!='?' && ans[j]!='?' && ans[j]!=s[j]) ans[j] = '!';
			else if (s[j]!='?' && ans[j] == '?') ans[j] = s[j];
		}
	}
	for (int i=0; i<ans.size(); i++){
		if (ans[i]=='!') cout << '?';
		else if (ans[i]=='?') cout << 'x';
		else cout << ans[i];
	}
	
	
}