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
	int n, p=0, k1=0, k2;
	LL ans=0;
	string s;
	cin >> n;
	cin >> s;
	k2 = n-1;
	while (k1<n && s[k1]=='.'){
		k1++;
		p++;
	}
	if (k1<n && s[k1]=='R'){
		ans+=p;
		p = 0;
	} else if (k1<n && s[k1]=='L'){
		p = 0;
	}
	if (k1 == n ){
		cout << n;
		return 0;
	}
	while (k2>=0 && s[k2]=='.'){
		k2--;
		p++;
	}
	if (k2>=0 && s[k2]=='L'){
		ans+=p;
		p = 0;
	} else if (k2>=0 && s[k2]=='R'){
		p = 0;
	}
	int q = 0;
	for (int i=k1; i<=k2; i++){
		if (s[i]=='L') {
			if (p%2==1) ans++;
			q = 1;
			p = 0;
		}
		else if (s[i]=='R'){
			if (p%2==1) ans++;
			q = 0;
			p = 0;
		} else if (q==0) p++;
		else ans++;
	}
	cout << ans;
}