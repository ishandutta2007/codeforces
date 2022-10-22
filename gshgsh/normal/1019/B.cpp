#include<iostream>
#include<cstdio>
using namespace std;
int ask(int x){cout<<"? "<<x<<endl;int y;cin>>y;return y;}
int main()
{
	int N;cin>>N;if(N&3){cout<<"! -1"<<endl;return 0;}
	int l=1,r=N/2+1,a=ask(l),b=ask(r),x=a-b,y=b-a;if(x==y){cout<<"! 1"<<endl;return 0;}
	while(1){int mid=l+r>>1,z=ask(mid)-ask((mid+N/2-1)%N+1);if(!z){cout<<"! "<<mid<<endl;return 0;}if(z*x<0)r=mid,y=z;else l=mid,x=z;}cout<<"! -1"<<endl;return 0;
}