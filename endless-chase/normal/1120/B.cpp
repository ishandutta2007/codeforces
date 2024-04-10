#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,del[111111],x; 
long long ans;
char a[111111],b[111111];
set<int> s;
int main()
{
	scanf("%d",&n);
	scanf("%s%s",a,b);
	for (int i=0;i<n;i++)
	{
		del[i]=b[i]-a[i];
		if (i) del[i]-=del[i-1];
	}
	if (del[n-1])
	{
		printf("-1\n");
		return Accepted;
	}
	for (int i=0;i<n;i++)
	{
		ans+=abs(del[i]);
	}
	printf("%lld\n",ans);
	for (int i=0;i<n-1;i++)
	{
		if (del[i]<0 && a[i]!='0' && a[i+1]!='0') s.insert(i);
		if (del[i]>0 && a[i]!='9' && a[i+1]!='9') s.insert(i); 
	}
	for (int i=1;i<=ans && i<=100000;i++)
	{
		x=*s.begin();s.erase(s.begin());
		if (s.find(x-1)!=s.end()) s.erase(s.find(x-1));
		if (s.find(x)!=s.end()) s.erase(s.find(x));
		if (s.find(x+1)!=s.end()) s.erase(s.find(x+1));
		printf("%d %d\n",x+1,(del[x]<0 ? -1 : 1));
		if (del[x]<0)
		{
			a[x]--;a[x+1]--;
			del[x]++;
		}
		else
		{
			a[x]++;a[x+1]++;
			del[x]--;
		}
		for (int j=max(0,x-1);j<=min(n-2,x+1);j++)
		{
			if (del[j]<0 && a[j]!='0' && a[j+1]!='0') s.insert(j);
			if (del[j]>0 && a[j]!='9' && a[j+1]!='9') s.insert(j);
		}
	}
	return Accepted;
}