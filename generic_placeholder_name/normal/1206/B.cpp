#include <bits/stdc++.h>
 
using namespace std;
int main() {
	int n, a, neg=0; long long sum=0; bool exists_0=0;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a;
		if (a>0) sum+=a-1;
		else if (a<0) {
			neg++; sum+=-a-1;
		}
		else {
			exists_0=1; sum++;
		}
	}
	if (neg%2==1&&exists_0==0) sum+=2;
	cout<<sum;
}