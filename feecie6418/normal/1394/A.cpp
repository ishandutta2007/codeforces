#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0,s[100005];
int d,n,a[100005],m;
int main(){
	cin>>n>>d>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int lst=n+1;
	for(int i=n;i>=1;i--)if(a[i]>m)lst=i;
	for(int i=n+1;i>=lst;i--){//i~n 
		if(i<=n&&1ll*(n-i)*(d+1)+1>n)break;
		int u=1ll*(n-i)*(d+1)+1;//n-u: 
		if(i>n)u=0;
		if(n-u<lst){
			ans=max(ans,s[n]-s[i-1]+s[lst-1]-s[lst-(n-u)-1]);
			continue;
		}
		//lst 
		ans=max(ans,s[n]-s[i-1]+s[lst-1]); 
	}
	cout<<ans;
}