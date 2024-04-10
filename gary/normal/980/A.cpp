#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int m1=a.size();
	int zz=0,xl=0;
	for(int i=0;i<m1;i++)
	{
		if(a[i]=='-')
		{
			xl++;
		}
		else
		{
			zz++;
		}
	}
	if(zz!=0)
	{
	    if(xl%zz!=0)
	    {
		    cout<<"NO";
	    }
	    else
	    {
		    cout<<"YES";
	    }
	}
	else
	{
		cout<<"YES";
	}
	return 0; 
}