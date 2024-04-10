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
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int n,m;
int main()
{
	cin>>n>>m;
	if(n==1&&m==1)
	{
		cout<<"0 0\n1 1\n1 0\n0 1\n";
	}
	else if(n==0||m==0)
	{
		
		if(n==0)
		{
			cout<<"0 1\n";
			cout<<0<<" "<<m<<endl;
			cout<<"0 0\n";
			cout<<0<<" "<<m-1<<endl;
		}
		else
		{
			cout<<"1 0\n";
			cout<<n<<" "<<0<<endl;
			cout<<"0 0\n";
			cout<<n-1<<" "<<0<<endl;
		}
	}
	else
	{
		if(n<m)
		{
			if(2*sqrt(m*m+n*n)+m<sqrt(m*m+n*n)+2*sqrt(m*m+(n-1)*(n-1)))
			{
				cout<<n-1<<" "<<m<<endl;
				cout<<"0 0\n";
				cout<<n<<" "<<m<<endl;
				cout<<"1 0\n";	
			}
			else
			{
				cout<<"0 0\n";
				cout<<n<<" "<<m<<"\n";
				cout<<n<<" 0\n";
				cout<<"0 "<<m<<"\n";
			}
		}
		else
		{
			if(2*sqrt(m*m+n*n)+n<sqrt(m*m+n*n)+2*sqrt((m-1)*(m-1)+n*n))
			{
				cout<<"0 1\n";
				cout<<n<<" "<<m<<endl;
				cout<<"0 0\n";
				cout<<n<<" "<<m-1<<endl;
			}
			else
			{
				cout<<"0 0\n";
				cout<<n<<" "<<m<<"\n";
				cout<<"0 "<<m<<"\n";	
				cout<<n<<" 0\n";	
			}
		}
	}
 //	system("pause");
	return 0;
}