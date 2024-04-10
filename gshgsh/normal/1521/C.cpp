#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 30001
int T,N,a[MAXN];
int ask1(int x,int y,int v){cout<<"? 1 "<<x<<' '<<y<<' '<<v<<endl;int ans;cin>>ans;return ans;}
int ask2(int x,int y,int v){cout<<"? 2 "<<x<<' '<<y<<' '<<v<<endl;int ans;cin>>ans;return ans;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int pos=N;
		For(i,1,N/2){int x=ask1(i*2-1,i*2,N-1);if(x==N){pos=i*2;break;}if(x==N-1&&ask1(i*2,i*2-1,N-1)==N){pos=i*2-1;break;}}
		For(i,1,N)a[i]=i!=pos?ask2(i,pos,1):N;cout<<"! ";For(i,1,N)cout<<a[i]<<" \n"[i==N];
	}
	return 0;
}