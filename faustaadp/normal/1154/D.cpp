#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,A,B,X,Y,i,ta;
void ber(ll aa)
{
	cout<<aa-1<<"\n";
	exit(0);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>n>>B>>A;
	X=A;
	Y=B;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		if(ta==0)
		{
			if(A>0)
				A--;
			else
			if(B>0)
				B--;
			else
				ber(i);
		}
		else
		{
			if(A==X&&A>0)
			{
				A--;
			}
			else
			if(B>0)
			{
				B--;
				A=min(A+1,X);
			}	
			else
			if(A>0)
				A--;
			else
				ber(i);
		}
		//cout<<A<<" "<<B<<"\n";
	}
	cout<<n<<"\n";
}