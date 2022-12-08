#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int sum=n*(n+1)/2,mi=-1;
	for(int i=2;i<=sum/i;i++)
		if(sum%i==0) {
			mi=i;
			break;
		}
	if(!~mi)puts("No");
	else {
		puts("Yes");
		cout<<1<<' '<<mi<<endl;
		cout<<n-1;
		for(int i=1;i<=n;i++)
			if(i!=mi)printf(" %d",i);
		puts("");
	}
	return 0;
}