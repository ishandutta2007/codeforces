#include <iostream>;
#include <stdio.h>;
#include <vector>;
#include <string>;
#include <algorithm>;
#include <queue>;
using namespace std;
/*int __cdecl sravni(const void *a, const void *b)
{
	const long long *i1= (const long long*) a;
	const long long *i2= (const long long*) b;
	return *i1 - *i2;
}*/


 
	//qsort(a,n,sizeof(long long), sravni);
//sort(a, a+n);
long long  t[100005], i, n, k,x , y, lvl[100005], a[500005], l, r, stdu[100005], cds[100005], f[100005], j, lvl1[100005];
vector<long long> v[100005], tv[100005];
vector<long long> c, ans, klk;
queue<long long> q;
int main()
{
	cin>>n;
	for(i=1; i<n;i++)
	{
		cin>>x>>y>>t[i];
		v[x].push_back(y);
		tv[x].push_back(t[i]); 
		v[y].push_back(x);
		tv[y].push_back(t[i]);
	}
	for(i=1; i<=n; i++)
	{
		lvl[i]=-1;
	}
	lvl[1]=0;
	a[0]=1;
	a[1]=0;
	l=0;
	r=1;

	while(r>=l)
	{
		x=a[l];
		y=a[l+1];
		lvl[x]=y;
		c=v[x];
		for(i=0; i<v[x].size();i++)
		{
			y=c[i];
			if(lvl[y]==-1)
			{
				a[r+1]=y;
				a[r+2]=lvl[x]+1;
				r=r+2;
			}
		}
		l=l+2;
	}
	for(i=1; i<=n; i++)
	{
		lvl1[i]=lvl[i];
		stdu[i]=lvl[i]*1000000+i;
	}
	sort(stdu+1, stdu+n+1);
	for(i=1; i<=n; i++)
	{
		lvl[i]=stdu[i]/1000000;
		cds[i]=stdu[i]%1000000;
	}
	for(i=0; i<n; i++)
	{
		c=v[cds[n-i]];
		f[cds[n-i]]=0;
		klk=tv[cds[n-i]];
		for(j=0; j<c.size(); j++)
		{
			if((lvl1[c[j]])>(lvl[n-i]))
			{

				if(f[c[j]]==0)
				{
					if(klk[j]==2)
					{
						f[cds[n-i]]++;
						ans.push_back(c[j]);
					}
					else
					{
						f[cds[n-i]]=f[cds[n-i]]+f[c[j]];
					}
				}
				else
				{
					f[cds[n-i]]=f[cds[n-i]]+f[c[j]];
				}
			}
		}
	}
	cout<<f[1]<<endl;
	for(i=0; i<ans.size(); i++)
	{
		cout<<ans[i];
		if((i+1)!=ans.size())
		{
			cout<<' ';
		}
	}
	return 0;
}