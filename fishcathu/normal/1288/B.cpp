#include<iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int m,n;x--;)
	{
		cin>>m>>n;
		int k=-1;
		for(n++;n;n/=10,k++);
		cout<<(long long)m*k<<endl;
	}
	return 0;
}