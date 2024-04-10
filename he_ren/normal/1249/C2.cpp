#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
const int LG = 38+5;

ll pw[LG];
int a[LG];

void solve(void)
{
	memset(a,0,sizeof(a));
	
	ll n;
	cin>>n;
	
	ll t=n;
	int cnt=-1,pos=-1;
	while(t)
	{
		++cnt;
		a[cnt]=t%3;
		if(a[cnt]==2) pos=cnt;
		t/=3;
	}
	
	if(pos==-1)
	{
		cout<<n<<endl;
		return;
	}
	for(int i=pos+1;; ++i)
		if(!a[i])
		{
			cout<< n/pw[i]*pw[i] + pw[i]<<endl;
			return;
		}
}

int main(void)
{
	pw[0]=1;
	for(int i=1; i<LG; ++i)
		pw[i] = pw[i-1]*3;
	
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}