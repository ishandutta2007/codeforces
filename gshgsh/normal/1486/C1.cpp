#include<iostream>
using namespace std;
int N;
int main()
{
	cin>>N;int l=1,r=N;
	while(l<r)
	{
		cout<<"? "<<l<<' '<<r<<endl;int x;cin>>x;
		int mid=l+r>>1;if(x<=mid){if(l==mid){l=mid+1;continue;}cout<<"  ? "<<l<<' '<<mid<<endl;int y;cin>>y;if(x==y)r=mid;else l=mid+1;}
		else {if(mid+1==r){r=mid;continue;}cout<<"? "<<mid+1<<' '<<r<<endl;int y;cin>>y;if(x==y)l=mid+1;else r=mid;}
	}
	cout<<"! "<<l<<endl;return 0;
}