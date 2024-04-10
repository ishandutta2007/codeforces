#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N;ll x,y;struct A{ll a,b;bool operator<(A x)const{return a<x.a;}}a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x>>y>>N;For(i,1,N)cin>>a[i].a;For(i,1,N)cin>>a[i].b;sort(a+1,a+N+1);
		For(i,1,N){int c=min((a[i].b+x-1)/x,(y+a[i].a-1)/a[i].a);y-=c*a[i].a;a[i].b-=c*x;if(y<=0)break;}cout<<(a[N].b<=0?"YES\n":"NO\n");
	}
	return 0;
}