#include <bits/stdc++.h>

using namespace std;
int main() {
	string a, b; int i, j, max=0;
	int fwd[199999]={0}, bwd[199999]={0};
	cin>>a>>b;
	j=0;
	for (i=0; i<a.length(); i++) {
		if (j<b.length()) {
			if (a[i]==b[j]) j++;
		}
		fwd[i]=j;
	}
	j=0;
	for (i=a.length()-1; i>=0; i--) {
		if (j<b.length()) {
			if (a[i]==b[b.length()-j-1]) j++;
		}
		bwd[i]=j;
	}
	for(i=0; i<a.length(); i++) {
		if (fwd[i]==b.length()) {
			if (max<a.length()-i-1) max=a.length()-i-1;
		}
	}
	for (j=a.length()-1; j>=0; j--) {
		if (bwd[j]==b.length()) {
			if (max<j) max=j;
		}
	}
	for(i=0; i<a.length(); i++) {
		for (j=a.length()-1; j>i; j--) {
			if (fwd[i]+bwd[j]==b.length()) {
				if (max<j-i-1) max=j-i-1;
			}
		}
	}
	cout<<max;
}