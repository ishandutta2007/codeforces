#include<bits/stdc++.h>
using namespace std;
int n,k,b[200005];
string ans,a;
int main() {
	cin>>n>>k>>a;
	cout<<n<<endl,ans.resize(n);
	for(int i=0;i<k;i++)ans[i]=a[i];
	for(int i=0;i+k<n;i++)ans[i+k]=ans[i];
	if(ans<a){
		ans[k-1]++;
		for(int i=k-1;i>=0;i--){
			if(ans[i]<='9')break;
			ans[i-1]++,ans[i]='0';
		}
		for(int i=0;i+k<n;i++)ans[i+k]=ans[i];
	}
	cout<<ans;
	return 0;
}