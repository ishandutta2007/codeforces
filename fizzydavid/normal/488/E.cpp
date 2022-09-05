//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n;
int kissme(int x,int k)
{
	int ans=1;
	while(k>0)
	{
		if(k&1)ans=1ll*ans*x%n;
		x=1ll*x*x%n;
		k=k/2;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	bool ok=0;
	for(int i=2;i*i<=n;i++)if(n%i==0)ok=1;
	if(n==1){cout<<"YES\n1\n";}
	else if(n==4){cout<<"YES\n1\n3\n2\n4\n";}
	else if(ok){cout<<"NO\n";}
	else{
		cout<<"YES\n1\n";
		for(int i=2;i<n;i++)cout<<1ll*i*kissme(i-1,n-2)%n<<endl;
		cout<<n<<endl;
	}
	return 0;
}