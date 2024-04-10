#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pld pair<ld,ld>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
#define deb(x) if(0)cerr<<#x<<" = "<<x<<"\n"
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}
const int inf=1e9+5,nax=1e6+5;

int rodz[nax];
ll d[nax],rep[nax];
int t[nax],num[nax];
ll eno=100123;

int pro()
{
	int z;
	cin>>z;
	RE(i,z){
		cin>>rodz[i];
		if(rodz[i]==1)cin>>num[i];
		else cin>>d[i]>>rep[i];
	}
	ll n=0;
	int zapy;
	cin>>zapy;
	int akt=0;
	while(zapy--){
		ll a;
		cin>>a;
		while((rodz[akt]==1 && n+1LL < a)|| (rodz[akt]==2 && n+d[akt]*rep[akt] < a)){
			ll memo=n;
			if(rodz[akt]==1 && n<eno)t[n++]=num[akt];
			RE(i,rep[akt])RE(j,d[akt]){
				if(n>eno){i=inf;j=inf;}
				else t[n++]=t[j];
			}
			if(rodz[akt]==1)n=memo+1LL;
			else n=memo+d[akt]*rep[akt];
			akt++;
		}
		if(rodz[akt]==1)cout<<num[akt];
		else{
			deb(a-1LL-n);
			deb(akt);
			cout<<t[(a-1LL-n)%d[akt]];
		}
		cout<<" ";
	}
	//RE(i,10)deb(t[i]);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int z=1;
	//cin>>z;
	RI(_,z)pro();
	return 0;
}