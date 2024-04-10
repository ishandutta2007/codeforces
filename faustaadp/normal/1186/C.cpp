#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,hz,p[2010101],has,i;
string A,B;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>A>>B;
	n=A.length();
	k=B.length();
	for(i=0;i<k;i++)
	{
	//	cout<<A[i]<<" "<<B[i]<<"_\n";
		if(A[i]!=B[i])hz++;
	}
	for(i=0;(i+1)<n;i++)
		p[i]=p[i-1]+(A[i]!=A[i+1]);
	has+=(hz%2==0);
	//cout<<hz<<"\n";
	for(i=k;i<n;i++)
	{
	//	hz+=(A[i-k]!=B[0]);
		//hz+=(A[i]!=B[k-1]);
		if(i==k)
			hz+=(p[i-1]);
		else
			hz+=(p[i-1]-p[i-k-1]);
		//hz+=p[i-1]-p[i-k];
		//cout<<i<<" "<<(p[i-1]-p[i-k])<<"\n";
		//cout<<hz<<"\n";
		has+=(hz%2==0);
	}
	cout<<has<<"\n";
}