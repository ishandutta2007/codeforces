#include <bits/stdc++.h>

using namespace std;
int main() {
	int n, i, t[99999], curr=1, prev=0, m=0;
	cin>>n;
	for(i=0;i<n;i++) cin>>t[i];
	for(i=1;i<n;i++) {
		if ((t[i]==t[i-1])&&(i<n-1)) curr++;
		else {
			if (i==n-1) {
				if (t[i]==t[i-1]) curr++;
				else {
					m=max(m, min(curr, prev)*2);
					prev=curr;
					curr=1;	
				}
			}
			m=max(m, min(curr, prev)*2);
			prev=curr;
			curr=1;
		}
	}
	cout<<m;
}