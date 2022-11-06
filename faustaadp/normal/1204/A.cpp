#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n;
ll cek(string aa)
{
	ll ii,sz=aa.length();
	for(ii=1;ii<sz;ii++)
		if(aa[ii]=='1')
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	n=s.length();
	if(cek(s))
		n--;
	n++;
	n/=2;
	cout<<n<<"\n";
}