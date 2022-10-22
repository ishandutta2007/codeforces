#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int main()
{
	cout<<'?';For(i,0,99)cout<<' '<<i;cout<<endl;int x;cin>>x;x>>=7;x<<=7;
	cout<<'?';For(i,1,100)cout<<' '<<(i<<7);cout<<endl;int y;cin>>y;y&=(1<<7)-1;
	cout<<"! "<<(x|y)<<endl;return 0;
}