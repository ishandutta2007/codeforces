#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2;
	int m;
	cin>>s1>>m;
	for(int l,r,k,i=0; i<m;i++) {
		cin>>l>>r>>k;
		l--; r--;
		s2 = s1;
		for(int j=l; j<=r; j++) {
			s1[l+((j-l+k)%(r-l+1))]=s2[j];
		}
	}
	cout<<s1;
	return 0;
}