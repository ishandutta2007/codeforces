#include<bits/stdc++.h>
using namespace std;
int n,a[105],tong[105];
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		memset(tong,0,sizeof tong);
		cin>>n;
		int minn=2147483647;
		for(int i=1;i<=n;++i)	cin>>a[i],++tong[a[i]],minn=min(minn,a[i]);
		cout<<n-tong[minn]<<endl;
	}
	return 0;
}