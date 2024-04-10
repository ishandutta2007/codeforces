#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,a[300005];
ll ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,j=0;i<=n;i++){
		j=max(j,i+1);
		while(a[i]%3){
			while(j<=n&&a[j]<2)j++;
			if(j>n)break;
			a[i]-=1,a[j]-=2,ans++;
		}
		ans+=a[i]/3;
	}
	cout<<ans;
}