#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],b[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int u=0;
	for(int i=2;i<=n;i+=2)b[i]=a[++u];
	for(int i=1;i<=n;i+=2)b[i]=a[++u];
	int cnt=0;
	for(int i=2;i<n;i++)if(b[i]<b[i+1]&&b[i]<b[i-1])cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
}