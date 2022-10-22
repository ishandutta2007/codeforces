#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000+1;
int n,k;
bool hotel[MAXN];
int p[MAXN];

bool cheq(int x) {
	for(int i=1; i<=n;i++) {
		if(!hotel[i]) {
		int ile = p[min(i+x,n)] - p[max(0,i-x-1)];
		if(ile>=k+1) return 1;
	}
	}
	return 0;
}
string s;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>s;
	for(int i=1; i<=n;i++) {
		hotel[i]=s[i-1]-'0';
		p[i] = p[i-1]+!hotel[i];
	}
	int pocz=0, kon=n,sr;
	while(pocz<=kon) {
		sr=(pocz+kon)/2;
		if(cheq(sr)) kon=sr-1;
		else pocz=sr+1;
	}
	cout<<kon+1;
	return 0;
}