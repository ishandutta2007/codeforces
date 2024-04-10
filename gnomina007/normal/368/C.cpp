#include <iostream>;
#include <stdio.h>;
#include <vector>;
#include <string>;
#include <algorithm>;
using namespace std;

/*int __cdecl sravni(const void *a, const void *b)
{
	const long long *i1= (const long long*) a;
	const long long *i2= (const long long*) b;
	return *i1 - *i2;
}*/

long long n, m,i, dl, sx[100005], sy[100005], sz[100005], lev[100005], prav[100005], bx, by, bz;
string s;
int main()
{
	cin>>s;
	dl=s.length();	
	for(i=1; i<=dl; i++)
	{
		if(s[i-1]=='x')
		{
			sx[i]=sx[i-1]+1;
			sy[i]=sy[i-1];
			sz[i]=sz[i-1];
		}
		if(s[i-1]=='y')
		{
			sy[i]=sy[i-1]+1;
			sx[i]=sx[i-1];
			sz[i]=sz[i-1];
		}
		if(s[i-1]=='z')
		{
			sz[i]=sz[i-1]+1;
			sy[i]=sy[i-1];
			sx[i]=sx[i-1];
		}
	}
	
	cin>>m;
	for(i=0; i<m; i++)
	{
		cin>>lev[i]>>prav[i];
	}

	for(i=0; i<m; i++)
	{
		if((prav[i]-lev[i])>1)
		{
		bx=sx[prav[i]]-sx[lev[i]-1];
		by=sy[prav[i]]-sy[lev[i]-1];
		bz=sz[prav[i]]-sz[lev[i]-1];
		if(abs(bx-by)<2)
		{
			if(abs(by-bz)<2)
			{
				if(abs(bz-bx)<2)
				{
					cout<<"YES";
				}
				else
				{
					cout<<"NO";
				}
			}
			else
			{
				cout<<"NO";
			}
		}
		else
		{
			cout<<"NO";
		}
		}
		else
		{
			cout<<"YES";
		}
		cout<<endl;


	}		
	return 0;
}



	//qsort(a,n,sizeof(long long), sravni);