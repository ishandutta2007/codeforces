
#include <iostream>;
#include <stdio.h>;
#include <vector>;
#include <algorithm>;
using namespace std;

int __cdecl sravni(const void *a, const void *b)
{
	const long long *i1= (const long long*) a;
	const long long *i2= (const long long*) b;
	return *i1 - *i2;
}

long long n, m,i, w[100005],sum, d, a[100005], b[100005], ans[100005], l[100005];
int main()
{
	cin>>n>>m;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}	
	//qsort(a,n,sizeof(long long), sravni);
	for(i=0; i<n; i++)
	{
		b[i]=0;
	}
	ans[n-1]=1;
	b[a[n-1]]=1;
	for(i=1; i<n; i++)
	{
		b[a[n-1-i]]++;
		if(b[a[n-1-i]]==1)
		{
			ans[n-i-1]=ans[n-i]+1;
		}
		else
		{
			ans[n-i-1]=ans[n-i];
		}
	}
	for(i=0; i<m; i++)
	{
		cin>>l[i];
	}
	for(i=0; i<m; i++)
	{
		cout<<ans[l[i]-1]<<endl;
	}



	return 0;
}