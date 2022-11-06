#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,A,B,i;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	if(k*(k-1)<n)cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		A=0;
		B=0;
		for(i=1;i<=n;i++)
		{
			A=(A+1)%k;
			B=(B+1)%k;
			if(A==0)A=k;
			if(B==0)B=k;
			if(A==1)
			{
				B=(B+1)%k;
				if(B==0)B=k;
			}
			cout<<A<<" "<<B<<"\n";
		}
	}
}