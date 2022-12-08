#include<bits/stdc++.h>
using namespace std;
long long len(long long x) {
	int sum=0;
	while(x) {
		sum++;
		x/=10;
	}
	return sum;
}
int t[50];
int main() {
	int q;
	cin>>q;
	while(q--) {
		long long a,slen=0;
		int cnt=1;
		cin>>a;
		while(a>slen+len(cnt)) {
			slen+=len(cnt);
			a-=slen;
			cnt++;
		}
		cnt=1;
		while(a>len(cnt)) {
			a-=len(cnt);
			cnt++;
		}
		int s=0;
		while(cnt) {
			t[s++]=cnt%10;
			cnt/=10;
		}
		cout<<t[s-a]<<endl;
	}
	return 0;
}