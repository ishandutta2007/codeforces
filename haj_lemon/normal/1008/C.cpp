#include<bits/stdc++.h>
using namespace std;
int l,r,ansn,a[100010],n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	while (r<=n){
		while (r<=n&&a[r]<=a[l]) r++;
		if (r>n) break;
		l++;r++;ansn++;
	}
	cout<<ansn<<endl;
	return 0;
}