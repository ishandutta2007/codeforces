#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll q,ma,ket,ta,ban,jum,i,a[505050];
long double has;
priority_queue<ll> pq1;
ll cek(ll aa)
{
	long double H=(long double)(jum+aa)/(long double)(ban+1);
	//cout<<H<<" "<<has<<"\n";
	if(has>H)
		return 1;
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>q;
	ma=-1;
	ket=-1;
	has=1e18;	
	for(i=1;i<=q;i++)
	{
		cin>>ta;
		if(ta==2)
		{
			if(has==1e18)
				cout<<fixed<<setprecision(10)<<(long double) 0<<"\n";
			else
				cout<<fixed<<setprecision(10)<<((long double)ma-has)<<"\n";
		}
		else
		{
			cin>>a[i];
			if(ket==-1||a[ket]<a[i])
			{
				if(ket!=-1)
				{
					pq1.push(-a[ket]);
					jum-=a[ket];
				}
				else
					ban++;
				jum+=a[i];
				ket=i;
				ma=a[ket];
				has=(long double)jum/(long double)ban;
			}
			else
				pq1.push(-a[ket]);
			while(!pq1.empty()&&cek(-pq1.top()))
			{
				ban++;
				jum-=pq1.top();
				has=(long double)jum/(long double)ban;
			//	cout<<ban<<" bj "<<jum<<" "<<pq1.top()<<"\n";	
				pq1.pop();
			}
		}
	}
}