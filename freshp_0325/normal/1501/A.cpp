#include<bits/stdc++.h>
using namespace std;
int T,a[105],b[105],t[105],n,sp[105];
int main(){
	cin>>T;
	while(T-->0)
	{
		cin>>n;
		for(int i=1;i<=n;++i)	cin>>a[i]>>b[i],sp[i]=(b[i]-a[i]+1)/2;
		for(int i=1;i<=n;++i)	cin>>t[i];
		int cur=0;
		for(int i=1;i<=n;++i)
		{
			cur+=t[i]+a[i]-b[i-1];
			if(i==n)	break;
			if(cur+sp[i]<=b[i])	cur=b[i];
			else	cur+=sp[i];
		}
		cout<<cur<<endl;
	}
	return 0;
}