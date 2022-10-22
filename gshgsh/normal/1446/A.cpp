#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N;ll W;struct A{ll a;int id;bool operator<(A x)const{return a<x.a;};}a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>W;For(i,1,N)cin>>a[i].a,a[i].id=i;sort(a+1,a+N+1);if(a[1].a>W){cout<<-1<<endl;continue;}
		ll sum=0;For(i,1,N){sum+=a[i].a;if(sum>=(W+1)/2){if(sum<=W){cout<<i<<endl;For(j,1,i)cout<<a[j].id<<' ';cout<<endl;}else if(a[i].a<=W){cout<<1<<endl<<a[i].id<<endl;}else cout<<-1<<endl;break;}}if(sum<(W+1)/2)cout<<-1<<endl;
	}
	return 0;
}