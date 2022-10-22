#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1,greater<int>());ll cnt1=0,cnt2=0;
		For(i,1,N){if((i&1)&&(a[i]+1&1))cnt1+=a[i];if((i+1&1)&&(a[i]&1))cnt2+=a[i];}cout<<(cnt1!=cnt2?cnt1>cnt2?"Alice\n":"Bob\n":"Tie\n");
	}
	return 0;
}