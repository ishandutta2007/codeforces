#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 51
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';}
		int x=0;For(i,1,N)if(a[i]==1||a[i]==4||a[i]==6||a[i]==8||a[i]==9){x=i;break;}if(x){cout<<"1\n"<<a[x]<<'\n';continue;}
		For(i,2,N)if(a[i]==2||a[i]==5){x=i;break;}if(x){cout<<"2\n"<<a[1]<<a[x]<<'\n';continue;}
		if(a[1]==2||a[1]==5)
		{
			For(i,2,N)if(a[i]==7){x=i;break;}if(x){cout<<"2\n"<<a[1]<<a[x]<<'\n';continue;}
			cout<<"2\n33\n";continue;
		}
		int cnt=0;For(i,1,N)cnt+=a[i]==3;if(cnt>=2){cout<<"2\n33\n";continue;}cout<<"2\n77\n";
	}
	return 0;
}