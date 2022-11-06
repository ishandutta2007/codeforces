#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
ll q,k,p[101010],d[101010],mo=1e9+7,ta,tb,i;
ll depe(ll aa)
{
	if(aa<k)return 1;	
	if(d[aa]==-1)
		d[aa]=(depe(aa-1)+depe(aa-k))%mo;
	return d[aa];
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>q>>k;
	memset(d,-1,sizeof(d));
	for(i=1;i<=100000;i++)
		p[i]=(p[i-1]+depe(i))%mo;
	while(q--)
	{
		cin>>ta>>tb;
		cout<<(p[tb]-p[ta-1]+mo)%mo<<"\n";
	}
}