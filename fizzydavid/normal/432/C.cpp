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
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
int pr[100111],pri,a[100111],n,pos[100111],gold[100111][2],cnt;
bool p[100111];
vector<pair<int,int> >ans;
int main()
{
	for(int i=2;i*i<=100000;i++)
	{
		if(!p[i])
		{
			for(int j=i*2;j<=100000;j+=i)
			{
				p[j]=1;	
			}
		}
	}
	for(int i=2;i<=100000;i++)if(!p[i])pr[++pri]=i;
	for(int i=1;i<=pri;i++)
	{
		for(int j=i;j<=pri;j++)
		{
			if(pr[i]+pr[j]<=100000)gold[pr[i]+pr[j]][0]=pr[i],gold[pr[i]+pr[j]][1]=pr[j];
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		int tp=pos[i],sum=pos[i]-i+1;
		if(sum==1)continue; 
		if(!p[sum])
		{
			cnt++;
			ans.pb(mp(i,tp));
			pos[a[i]]=pos[i];
			a[pos[i]]=a[i];
		}
		else
		{
			if(sum&1)
			{
				sum++;cnt+=2;
				int x=gold[sum][0],y=gold[sum][1];
				ans.pb(mp(pos[i]-x+1,pos[i]));
				ans.pb(mp(i,pos[i]-x+1));
				pos[a[i]]=pos[i]-x+1;
				pos[a[pos[i]-x+1]]=pos[i];
				a[pos[i]]=a[pos[i]-x+1];
				a[pos[i]-x+1]=a[i];
			}
			else
			{
				cnt++;
				ans.pb(mp(pos[i]-1,pos[i]));
				pos[a[pos[i]-1]]=pos[i];
				a[pos[i]]=a[pos[i]-1];
				a[pos[i]-1]=i;pos[i]--;i--;
			}
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
	{
		printf("%d %d\n",ans[i].ff,ans[i].ss);
	}
//	system("pause");
	return 0;
}