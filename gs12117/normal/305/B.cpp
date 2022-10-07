#include<iostream>

int main()
{
	long long p,q,i,n,a;
	std::cin>>p>>q;
	std::cin>>n;
	for(i=0;i<n;i++)
	{
		std::cin>>a;
		if(q==0)break;
		if(a>p/q)break;
		p-=q*a;
		p^=q^=p^=q;
	}
	std::cout<<(i<n||q!=0?"NO":"YES");
}