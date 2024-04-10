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
#define st first
#define nd second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
#define deb(x) cerr<<#x<<" = "<<x<<"\n"
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}
const int inf=1e9+5,nax=1e6+5;

bool pot[nax];
int ojc[nax],lvl[nax],l[nax],r[nax],x[nax],val[nax],rodz[nax];
int n,m;
vector<pii > w[nax];
vector<int> res[nax];

int pro()
{
	RE(i,19)pot[1<<i]=1;
	int akt=1;
	RI(i,700123){
		ojc[akt++]=i;
		if(pot[i])ojc[akt++]=i;
	}
	
	cin>>n>>m;
	RI(i,m){
		cin>>rodz[i];
		if(rodz[i]==1)cin>>lvl[i]>>l[i]>>r[i]>>x[i];
		else{
			cin>>lvl[i]>>val[i];
			w[lvl[i]].pb(mp(val[i],i));
		}
	}
	RI(i,n){
		w[i].pb(mp(inf,inf));
		sort(all(w[i]));
	}
	
	RI(i,m){
		if(rodz[i]==1){
			int a=l[i],b=r[i];
			for(int P=lvl[i];P;--P){
				int akt=0;
				while(w[P][akt].st<a)akt++;
				while(w[P][akt].st<=b){
					res[w[P][akt].nd].pb(x[i]);
					akt++;
				}
				a=ojc[a];
				b=ojc[b];
			}
		}
		else{
			res[i].pb(-1);
			sort(all(res[i]));
			int a=0;
			RI(j,res[i].size()-1)if(res[i][j]!=res[i][j-1])a++;
			cout<<a<<"\n";
		}
	}
	
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