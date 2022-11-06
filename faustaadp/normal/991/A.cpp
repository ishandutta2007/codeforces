#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll N,A,B,C;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>A>>B>>C>>N;
	if(min(A,B)<C)
	{
		cout<<-1<<"\n";
		return 0;
	}
	if((A+B-C)>=N)
	{
		cout<<-1<<"\n";
		return 0;
	}
	cout<<N-(A+B-C)<<"\n";
}