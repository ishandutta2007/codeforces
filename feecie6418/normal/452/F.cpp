#include<bits/stdc++.h>
using namespace std;
int a[300005],n,t,pos[300005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i;
	bool flag=0;
	for(int i=1;i<=n&&!flag;i++){
		for(int j=i+1;j<=min(i+40,n);j++)if(2*a[j]-a[i]<=n&&2*a[j]-a[i]>=1&&pos[2*a[j]-a[i]]>j)flag=1;
		for(int j=i-1;j>=max(i-40,1);j--)if(2*a[j]-a[i]<=n&&2*a[j]-a[i]>=1&&pos[2*a[j]-a[i]]<j)flag=1;
	}
	puts(flag?"YES":"NO");
}