#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll N,i,b[5050][110],has,S1,S2;
vector<ll> v;
void hey(ll aa,ll bb)
{
//	cout<<aa<<" "<<bb<<"\n";
	if(b[aa][bb])	
		return ;
	b[aa][bb]=1;
	if(bb==N)
		has++;
	else
	{
		hey(aa+1,bb+1);
		hey(aa+5,bb+1);
		hey(aa+10,bb+1);
		hey(aa+50,bb+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>N;
	if(N<=100)
		hey(0,0);
	else
		has=N*49-(12+236)+1;
	cout<<has<<"\n";
}