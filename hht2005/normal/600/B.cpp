#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],b;
int ef(int l,int r)//????
{
	if(l==r)return l;
	int m=(l+r)>>1;
	if(a[m]>b)return ef(l,m);
	else return ef(m+1,r);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];//??
	sort(a+1,a+n+1);//??
	for(int i=0;i<m;i++)
		cin>>b,cout<<ef(1,n+1)-1<<" ";//??,????
	return 0;
}