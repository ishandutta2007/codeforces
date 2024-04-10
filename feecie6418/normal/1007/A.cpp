#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int a[100005],n,ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&a[j]==a[i])j++;
		if(j<=n)ans++,j++;
	}
	cout<<ans;
}