#include<iostream>
using namespace std;
int N;
int main()
{
	cin>>N;cout<<"? "<<1<<' '<<N<<endl;int x;cin>>x;int y=2;if(x>1){cout<<"? "<<1<<' '<<x<<endl;cin>>y;}
	if(y==x){int l=1,r=x-1,ans=1;while(l<=r){int mid=l+r>>1;cout<<"? "<<mid<<' '<<x<<endl;int z;cin>>z;if(z==x)ans=mid,l=mid+1;else r=mid-1;}cout<<"! "<<ans<<endl;return 0;}
	int l=x+1,r=N,ans=N;while(l<=r){int mid=l+r>>1;cout<<"? "<<x<<' '<<mid<<endl;int z;cin>>z;if(z==x)ans=mid,r=mid-1;else l=mid+1;}cout<<"! "<<ans<<endl;return 0;
}