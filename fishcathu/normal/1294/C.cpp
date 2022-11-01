#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int a;x--;)
	{
		cin>>a;
		int b[2]={0},i,j;
		for(i=2,j=0;i*i<a;i++)
		{
			if(a%i==0)
			{
				a/=i,b[j]=i,j++;
				if(j==2)break;
			}
		}
		if(b[1]==0)
		{
			cout<<"NO\n";
			continue;
		}
		else cout<<"YES\n"<<b[0]<<' '<<b[1]<<' '<<a<<endl;
	}
	return 0;
}