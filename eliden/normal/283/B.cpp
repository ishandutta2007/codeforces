#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repeq(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const int sz=2e5+1;
bool on[2][sz], done[2][sz];
int n;
ll b[2][sz], a[sz];

ll getb(int step,int i)
{
	if(i<=0||i>n)
		return 0;
	if(i==1 || on[step][i])
	{
		b[step][i]=-1;
		done[step][i]=true;
		return -1;
	}
	if(done[step][i])
		return b[step][i];
	on[step][i] = true;
	int j;
	if(step==0)
		j=i+a[i];
	else
		j=i-a[i];
	ll x = getb(1-step,j);
	if(x<0)
		b[step][i]=-1;
	else
		b[step][i]=x+a[i];
	on[step][i] = false;
	done[step][i]=true;
	return b[step][i];
	
}
int main()
{
	scanf("%d",&n);
	int ai;
	repeq(i,2,n)
	{
		scanf("%d",&ai);
		a[i]=ai;
	}
	repeq(i,1,n)
		for(int step=0;step<2;++step)
		{
			on[step][i]=false;
			done[step][i]=false;
		}
	repeq(i,2,n)
	{
		ll x = getb(1,i);
		if(x==-1)
			printf("-1\n");
		else
		{
			cout<<i-1+x<<"\n";
		}
	}
}