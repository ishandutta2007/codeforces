#include <bits/stdc++.h>

using namespace std;

int a,b,c,x,y,z;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>x>>y>>z>>a>>b>>c;
	if(a<x) {
		cout<<"NO"; return 0;
	}
	a-=x;
	if(a+b<y) {
		cout<<"NO"; return 0;
	}
	if(a+b+c-y<z) {
		cout<<"NO"; return 0;
	}
	cout<<"YES";
	return 0;
}