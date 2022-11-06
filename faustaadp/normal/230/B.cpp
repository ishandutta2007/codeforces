#include<bits/stdc++.h>
using namespace std;
vector<bool> p(1000010,0);
long long n,x,ta,i,j,hh;
bool b;
string s;
int main()
{
	//cin>>n>>x;
	//scanf("%d %d",&n,&x);
	n=1000001;
	for(i=2;i<=sqrt(n);i++)
	{
		if(p[i]==0)
		{
			for(j=i*i;j<=n;j=j+i)
			{
				if(!p[j]) hh++;
				p[j]=1;
			}
		}
	}
	p[1]=1;
	cin>>x;
	for(i=1;i<=x;i++)
	{
		cin>>ta;
		b=0;
		if((long long)sqrt(ta)*(long long)sqrt(ta)==ta)
		{
			if(!p[(long long)sqrt(ta)])
				b=1;
		}
		s=b?"YES":"NO";
		cout<<s<<endl;
	}
}