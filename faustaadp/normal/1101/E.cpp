#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll q,ta,tb,X,Y;
char tc;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>q;
	while(q--)
	{
		cin>>tc>>ta>>tb;
		if(tb<ta)swap(ta,tb);
		//cout<<ta<<" "<<tb<<"\n";
		if(tc=='+')
		{
			X=max(X,ta);
			Y=max(Y,tb);
		}
		else
		{
			if(X<=ta&&Y<=tb)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}