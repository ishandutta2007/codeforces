#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,a[150005];
ll ans[150005];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(*max_element(a,a+n)==0){
		puts("YES");
		for(int i=1;i<=n;i++)cout<<"1 ";
		return 0;
	}
	const ll W=1e12;
	for(int i=0;i<n;i++)
		if(a[i]<a[(i+1)%n]){
			ans[(i+1)%n]=a[(i+1)%n];
			ans[i]=W*a[(i+1)%n]+a[i];
			for(int j=1;j<n-1;j++){
				ans[(i-j+n)%n]=a[(i-j+n)%n]+ans[(i-j+1+n)%n];
			}
			puts("YES");
			for(int j=0;j<n;j++)cout<<ans[j]<<' ';
			return 0;
		}
	puts("NO");
}