#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;int cnt=0;For(i,1,N){char c;cin>>c;cnt+=a[i]=c=='M';}if(cnt*3!=N){cout<<"NO\n";continue;}
		bool flag=1;int tot=0;For(i,1,N)if(!a[i])tot++;else{tot--;if(tot<0){flag=0;break;}}tot=0;FOR(i,N,1)if(!a[i])tot++;else{tot--;if(tot<0){flag=0;break;}}
		cout<<(flag?"YES\n":"NO\n");
	}
	return 0;
}