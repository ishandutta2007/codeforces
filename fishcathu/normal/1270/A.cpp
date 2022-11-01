#include<iostream> 
using namespace std;
int main()
{
	
	int x;
	cin>>x;
	for(int n,a,b;x--;)
	{
		cin>>n>>a>>b;
		int k=0;
		for(int i;a--;)
		{
			cin>>i;
			if(i==n)k=1;
		}
		for(int i;b--;)cin>>i;
		cout<<(k?"YES\n":"NO\n");
	}
	return 0;
}