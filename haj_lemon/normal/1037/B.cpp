#include<bits/stdc++.h>
using namespace std;
int n,a[200010],s;
long long ansn;
int main(){
	cin>>n>>s;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if (a[(n+1)/2]<s){
		for (int i=(n+1)/2;i<=n;i++)if (a[i]<s) ansn+=s-a[i];
	}else{
		for (int i=1;i<=(n+1)/2;i++) if (a[i]>s) ansn+=a[i]-s;
	}
	cout<<ansn<<endl;
	return 0;
}