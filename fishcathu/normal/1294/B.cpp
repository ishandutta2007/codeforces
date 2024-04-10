#include<iostream>
#include<algorithm>
using namespace std;
struct s
{
	int a,b;
	bool operator<(const s m)const
	{
		return this->a<=m.a&&this->b<=m.b;
	}
};
int main()
{
	int x;
	cin>>x;
	for(int n;x--;)
	{
		cin>>n;
		s d[n+1];
		d[0].a=0,d[0].b=0;
		for(int i=1;i<=n;i++)cin>>d[i].a>>d[i].b;
		sort(d,d+n+1);
		int i=1;
		for(;i<=n&&d[i].a>=d[i-1].a&&d[i].b>=d[i-1].b;i++);
		if(i<=n)
		{
			cout<<"NO\n";
			continue;
		}
		else cout<<"YES\n";
		for(i=1;i<=n;i++)
		{
			for(int j=d[i].a-d[i-1].a;j--;)cout<<'R';
			for(int j=d[i].b-d[i-1].b;j--;)cout<<'U';
		}
		cout<<endl;
	}
	return 0;
}