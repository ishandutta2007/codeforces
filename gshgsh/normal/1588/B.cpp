#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
ll ask(int l,int r){cout<<"? "<<l<<' '<<r<<endl;ll x;cin>>x;return x;}
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int N;cin>>N;ll x=ask(1,N);
		int l=1,r=N-2,pos=1;while(l<=r){int mid=l+r>>1;if(ask(mid,N)==x)pos=mid,l=mid+1;else r=mid-1;}
		ll y=ask(pos+1,N);int pos2=pos+x-y+1;int pos3=pos2+ask(pos2,N)-ask(pos2+1,N);
		cout<<"! "<<pos<<' '<<pos2<<' '<<pos3<<'\n';
	}
	return 0;
}