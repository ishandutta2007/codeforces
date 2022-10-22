#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int ask(int l,int r){cout<<"? "<<l<<' '<<r<<endl;int x;cin>>x;return x;}
int main()
{
	int N,K;cin>>N>>K;
	if(N&1)
	{
		vector<int>a(N),ans(N+1);
		For(i,2,N){int x=K;while(x==K)ask(i-1,i),x=ask(i-1,i);a[i-1]=x+K>N?2:x+K==N?1:0;while(x!=K)ask(i-1,i),x=ask(i-1,i);}
		bool flag=0;For(i,1,N-1)if(a[i]!=1){ans[i]=ans[i+1]=a[i]>>1;FOR(j,i-1,1)ans[j]=a[j]-ans[j+1];For(j,i+2,N)ans[j]=a[j-1]-ans[j-1];flag=1;break;}
		if(!flag)For(i,1,N)ans[i]=i+(K<<1<N)&1;cout<<"! ";For(i,1,N)cout<<ans[i];cout<<endl;return 0;
	}
	vector<int>ans(N+1);For(i,1,N){int x=K;while(x==K)ask(i,i),x=ask(i,i);ans[i]=x+K>N;while(x!=K)ask(i,i),x=ask(i,i);}
	cout<<"! ";For(i,1,N)cout<<ans[i];cout<<endl;return 0;
}