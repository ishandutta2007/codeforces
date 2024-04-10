#include<iostream>
using namespace std;
int main()
{ 
	int x;
	cin>>x;
	for(int a,b,c,d;x--;)
	{
		cin>>a>>b>>c>>d;
		if(a>b)a^=b,b^=a,a^=b;
		int m=c-d-a,n=b-c-d,k=b-a,ans=0;
		if(m>0)ans+=m;
		if(n>0)ans+=n;
		if(k<0)k=-k;
		cout<<(ans<k?ans:k)<<endl;
	}
	return 0;
}