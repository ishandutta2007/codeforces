#include<iostream>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define F first
#define S second
#define MAXN 200001
int T,N,M;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;map<int,int>a;For(i,1,M){int x,y;cin>>x>>y;a[y]+=x;}
		int lst=-1;bool flag=1;for(auto i:a){if(lst==-1){if(i.S!=3)lst=i.F+i.S;}else{if(i.S==3||(lst+i.F+i.S)%2==0){flag=0;break;}lst=-1;}}cout<<(flag&&lst==-1?"YES\n":"NO\n");
	}
	return 0;
}