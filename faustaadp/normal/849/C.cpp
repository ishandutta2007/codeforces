#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,i,a[1010],j,k,te;
double t1,t2,ti,kus;
bool bb,ba;
int main()
{
//	t=100000;
	for(i=0;i<1000;i++)
		a[i]=(i*(i+1))/2;
//	while(t--)
	{
		j=0;
//		n=t;
//		cout<<n<<"  ";
		cin>>n;
		if(n==0)
		{
			cout<<"a\n";
			return 0;
		}
		while(n>0)
		{
	//		cout<<".";
			j++;
			te=upper_bound(a,a+1000,n)-a;
			//cout<<te<<" "<<a[te-1]<<" "<<n<<"\n";
			for(i=1;i<=te;i++)
				cout<<char(j+'a'-1);
			n=n-a[te-1];
			//cin>>kus;
		}
//		if(j>=26)
	//	{
//			cout<<j<<" "<<n<<"\n";
	//		break;
	//	}
		cout<<"\n";
	}
}