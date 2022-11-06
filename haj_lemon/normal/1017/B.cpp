#include<bits/stdc++.h>
using namespace std;
long long n,sum0,sum1,sum2,sum3;
char c1[100010],c2[100010];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>c1[i];
	for (int i=1;i<=n;i++)cin>>c2[i];
	for (int i=1;i<=n;i++){
		if (c1[i]=='0'&&c2[i]=='0') sum0++;
		if (c1[i]=='0'&&c2[i]=='1') sum1++;
		if (c1[i]=='1'&&c2[i]=='0') sum2++;
		if (c1[i]=='1'&&c2[i]=='1') sum3++;
	}
	cout<<sum0*sum2+sum0*sum3+sum1*sum2<<endl;
	return 0;
}