#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffff
#define MAXN 200001
int T,N,x[MAXN],ans[MAXN];struct A{int x,y,id;bool operator<(A a)const{return x<a.x;}}a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i].x>>a[i].y,a[i].id=i,a[i].x>a[i].y?swap(a[i].x,a[i].y),0:0;sort(a+1,a+N+1);a[0].y=INF;
		int l=0,id=0;For(i,1,N){while(l<N&&a[l+1].x<a[i].x)l++,a[l].y<a[id].y?id=l:0;ans[a[i].id]=a[id].y<a[i].y?a[id].id:-1;}
		For(i,1,N)cout<<ans[i]<<' ';cout<<endl;
	}
	return 0;
}