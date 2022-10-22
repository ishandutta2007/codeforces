#include <bits/stdc++.h>
using namespace std;

const int nax = 200*1000+10;
int n,t;
int a[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i];
		if(a[i]==n) t = i;
	}
	bool ok = 1;
	for(int i=t; i>=1; i--) if(a[i]<a[i-1]) ok=0;
	for(int i=t; i<n-1; i++) if(a[i]<a[i+1]) ok=0;
	if(ok) cout<<"yes";
	else cout<<"no";
}