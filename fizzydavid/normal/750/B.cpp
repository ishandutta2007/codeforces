//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n;
int main()
{
	cin>>n;
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		int x;string s;
		cin>>x>>s;
		if(s=="South")pos+=x;
		else if(s=="North")pos-=x;
		if(pos<0||pos>20000||(pos==0||pos==20000)&&(s=="East"||s=="West"))
		{
			puts("NO");
			return 0;
		}
	}
	if(pos==0)puts("YES");else puts("NO");
	return 0;
}