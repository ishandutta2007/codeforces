#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define mp make_pair
#define F first
#define S second
#define MAXN 5001
int T,N;Pair a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i].F,a[i].S=i;sort(a+1,a+N+1);if(a[1].F==a[N].F){cout<<"NO\n";continue;}
		cout<<"YES\n";int id;For(i,2,N)if(a[i].F!=a[1].F){id=i;break;}For(i,id,N)cout<<a[1].S<<' '<<a[i].S<<endl;For(i,2,id-1)cout<<a[i].S<<' '<<a[id].S<<endl;
	}
	return 0;
}