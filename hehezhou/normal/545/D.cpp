#include<bits/stdc++.h>
using namespace std;
int a[100010],n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+1+n);
	for(int i=1,now=0;i<=n;i++)
		if(now<=a[i])now+=a[i],ans++;
	return cout<<ans,0;
}