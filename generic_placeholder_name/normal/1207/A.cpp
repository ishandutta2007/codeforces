#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
int main () {
	long long t, cal;
	long long b, p, f, h, c;
	cin>>t;
	for (int i=1; i<=t; i++){
		cin>>b>>p>>f>>h>>c;
		if (b>=2*(p+f)) cout << p*h + f*c;
		else {
			if (h>c) {
				cal = b/2;
				if (cal<=p) cout << cal*h; 
				else cout << p*h + (cal-p)*c; 
			}
				else {
				cal = b/2;
				if (cal<=f) cout << cal*c; 
				else cout << f*c + (cal-f)*h; 
			}
		}
		cout<<endl;
	}
}