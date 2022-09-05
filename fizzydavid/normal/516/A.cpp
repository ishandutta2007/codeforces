//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int pr[4]={2,3,5,7};
int n,cnt[10];
void add(int d)
{
	for(int i=2;i<=d;i++)cnt[i]++;
}
int main()
{
	cin>>n;char c;int d;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		d=c-'0';
		for(int i=d;i>=2;i--)
		{
			if(i==9)cnt[3]+=2;
			else if(i==8)cnt[2]+=3;
			else if(i==6)cnt[2]++,cnt[3]++;
			else if(i==4)cnt[2]+=2;
			else
			{
				add(i);
				break;
			}
		}
	}
	int tmp=0;
	for(int i=9;i>=2;i--)
	{
		for(int j=0;j<cnt[i]-tmp;j++)cout<<i;
		tmp=max(tmp,cnt[i]);
	}
	cout<<endl;
	return 0;
}