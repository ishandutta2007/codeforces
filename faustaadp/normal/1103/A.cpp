#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n,A,B,i;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	n=s.length();
	A=1;
	B=1;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			cout<<1<<" "<<A<<"\n";
			A=(A+1)%4;
			if(A==0)A=4;
		}
		else
		{
			cout<<4<<" "<<B<<"\n";
			B=(B+2)%4;
			if(B==0)B=4;
		}
	}
}