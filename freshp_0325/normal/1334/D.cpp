#include<cstdio>
#include<algorithm>
#include<queue>
#include<climits>
#include<iostream>
using namespace std;
long long n;
int main(){
	long long T;
	cin>>T;
	while(T-->0)
	{
		long long l,r;
		cin>>n>>l>>r;
		long long cnt=0;
		for(int i=1;i<=n-1;++i)
		{
			long long p=max(l,cnt+1),q=min(cnt+2*(n-i),r);
			p-=cnt,q-=cnt;
			cnt+=2*(n-i);
			if(q<p)	continue;
			if(p%2==0)	cout<<i+p/2<<' ',++p;
			for(int j=i+(p+1)/2;j<=i+q/2;++j)	cout<<i<<' '<<j<<' ';
			if(q&1)	cout<<i<<' ';
		}
		if(r==n*(n-1)+1)	cout<<1;
		cout<<"\n";
	}
	return 0;
}