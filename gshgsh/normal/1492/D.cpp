#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int a,b,k;
int main()
{
	cin>>a>>b>>k;if(!a){if(!k){cout<<"Yes\n";For(i,1,b)cout<<1;cout<<endl;For(i,1,b)cout<<1;}else cout<<"No\n";return 0;}
	if(b==1){if(!k){cout<<"Yes\n1";For(i,1,a)cout<<0;cout<<"\n1";For(i,1,a)cout<<0;}else cout<<"No\n";return 0;}if(k>a+b-2){cout<<"No\n";return 0;}
	cout<<"Yes\n";For(i,1,b)cout<<1;For(i,1,a)cout<<0;cout<<endl;if(k<=a){For(i,1,b-1)cout<<1;For(i,1,k)cout<<0;cout<<1;For(i,1,a-k)cout<<0;return 0;}
	For(i,1,a+b-k-1)cout<<1;cout<<0;For(i,1,k-a)cout<<1;For(i,1,a-1)cout<<0;cout<<1;return 0;
}