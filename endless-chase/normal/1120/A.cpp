#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,k,m,s,cnt[555555],cnp[555555],a[555555],x,r,rep,lst;
vector<int> res;
int main()
{
	scanf("%d%d%d%d",&m,&k,&n,&s);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1;i<=s;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	memcpy(cnp,cnt,sizeof(cnt));
	r=1;
	for (int i=1;i<=m-k+1;i++)
	{
		while(r<=m)
		{
			if (r-i+1>=k && rep>=s) break;
			cnp[a[r]]--;
			if (cnp[a[r]]>=0) rep++;
			if (r-i+1<k) 
			{
				r++;
				continue;
			}
			r++;
			if (rep>=s) break;
		}
		if ((i-1)/k+(m-r+1)/k+1>=n && rep>=s)
		{
			for (int j=1;j<=(i-1)%k;j++) res.push_back(j);
			lst=r-i;
			for (int j=i;j<r;j++)
			{
				if (cnp[a[j]]<0)
				{
					if (lst>k)
					{
						cnp[a[j]]++;
						lst--;
						res.push_back(j); 
					}
				}
			} 
			printf("%d\n",res.size());
			for (int i=0;i<res.size();i++) printf("%d ",res[i]);
			printf("\n");
			return Accepted;
		}
		cnp[a[i]]++;
		if (cnp[a[i]]>0) rep--;
	}
	printf("-1\n");
	return Accepted;
}