#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	a=min(a,b);
	long long ans=1;
	for(int i=1;i<=a;i++)
		ans*=i;
	cout<<ans<<endl;
}