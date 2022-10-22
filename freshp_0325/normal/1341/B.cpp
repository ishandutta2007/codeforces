#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[200005],tops[200005];
int main(){
	int T;
	cin>>T;
	while(T-->0)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)	cin>>a[i];
		for(int i=3;i<=n;++i)	tops[i]=tops[i-1]+int(bool(a[i-1]>a[i-2] && a[i-1]>a[i]));
		int maxn=0,where=1;
		for(int i=1;i<=n-k+1;++i)	if(tops[i+k-1]-tops[i]-int(bool(tops[i]!=tops[i+1]))>maxn)	maxn=tops[i+k-1]-tops[i],where=i;
		cout<<maxn+1<<' '<<where<<endl;
	}
	return 0;
}