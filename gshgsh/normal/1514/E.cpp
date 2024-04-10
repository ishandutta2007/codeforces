#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
int T,N,a[MAXN],b[MAXN],ans[MAXN][MAXN];
bool ask1(int x,int y){cout<<"1 "<<x<<' '<<y<<endl;int ans;cin>>ans;return ans;}bool ask2(int x,int r){cout<<"2 "<<a[x]<<' '<<r+1<<' ';For(i,0,r)cout<<a[i]<<' ';cout<<endl;int ans;cin>>ans;return ans;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,0,N-1)a[i]=i;For(i,0,N-1)For(j,0,N-1)ans[i][j]=1;stable_sort(a,a+N,ask1);
		int j=N-1;FOR(i,N-1,0){if(i==j){For(k,i+1,N-1)For(l,0,i)ans[a[k]][a[l]]=0;j--;}while(ask2(i,j))j--;}cout<<3<<endl;For(i,0,N-1){For(j,0,N-1)cout<<ans[i][j];cout<<endl;}int x;cin>>x;
	}
	return 0;
}