#include<bits/stdc++.h>
using namespace std;////
string a[50],b[50];
int main() {
	int n,m,q,t;///
	scanf("%d%d",&n,&m);//
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];///
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&t);
		cout<<a[(t-1)%n]<<b[(t-1)%m]<<endl;
	}///
	return 0;
}