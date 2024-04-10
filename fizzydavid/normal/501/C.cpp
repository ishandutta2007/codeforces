#include<bits/stdc++.h>
using namespace std;
#define PB push_back 
struct num{int d,sum;}a[70000];
int n,ans;
vector<int>con[70000];
void fun(int i)
{
	if(a[i].d==1)
	{
		con[a[i].sum].PB(i);
		con[i].PB(a[i].sum);
		a[a[i].sum].sum^=i;
		a[a[i].sum].d--;a[i].d--;
		ans++;
		if(a[a[i].sum].d==1)fun(a[i].sum);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].d>>a[i].sum;
	for(int i=0;i<n;i++)fun(i);
	cout<<ans<<endl;
	for(int i=0;i<n;i++)for(int j=0;j<con[i].size();j++)if(i<con[i][j])cout<<i<<" "<<con[i][j]<<endl;
}