#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int q,n,K,ta,tb,a[505050],x[755][755],jaw,i;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>q;
	n=500000;
	//cout<<K<<"\n";
	//K=0;
	K=500;
	while(q--)
	{
		cin>>ta;
		if(ta==1)
		{
			cin>>ta>>tb;
			a[ta]+=tb;
			for(i=1;i<(K+1);i++)
				x[i][ta%i]+=tb;
		}
		else
		{
			cin>>ta>>tb;
			jaw=0;
			if(ta<=K)
				jaw=x[ta][tb];
			else
				for(i=tb;i<(n+1);i+=ta)
					jaw+=a[i];
			cout<<jaw<<"\n";
		}
	}
}