#include<bits/stdc++.h>
using namespace std;
unsigned long long yz,yy,a,b,n,i,ff;
bool bb;
bool paw(unsigned long long xx)
{
	if(xx<=1)
		return 1;
	else
	if(pow(2,yy)==xx)
		return 1;
	else
		return 0;
}
int main()
{
	//while(cin>>n>>a)
	//{
	cin>>n>>a;
	bb=0;
	ff=a;
	while(bb==0)
	{
		yy=log2(ff);
		yz=pow(2,yy);
	//	cout<<ff;
		if(paw(ff))
		{
			cout<<yy+1<<endl;
			break;
			bb=1;
		}
		ff=ff-yz;
	}
	//}
}