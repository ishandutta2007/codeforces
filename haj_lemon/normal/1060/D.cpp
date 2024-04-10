#include<bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010];
long long ansn;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) ansn=ansn+max(a[i],b[i])+1;
	cout<<ansn<<endl;
	return 0;
}