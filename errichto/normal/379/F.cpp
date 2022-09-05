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
#define deb(x) cerr<<#x<<" = "<<x<<"\n"
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}
const int inf=1e9+5,nax=5e6+5;
vi w[nax];
int tr[nax],akt,h[nax],tam[nax],n,pot;

void dfs(int a){
	tam[a]=akt;
	tr[akt++]=h[a];
	RE(i,w[a].size()){
		int b=w[a][i];
		if(!tam[b]){
			h[b]=h[a]+1;
			dfs(b);
			tr[akt++]=h[a];
		}
	}
}

int odl(int a,int b){
	int r=h[a]+h[b];
	a=tam[a];b=tam[b];
	if(a>b)swap(a,b);
	int lca=inf;
	mini(lca,tr[a]);
	mini(lca,tr[b]);
	while(a<b-1){
		mini(lca,tr[a+1]);
		mini(lca,tr[b-1]);
		a/=2;b/=2;
	}
	return r-2*lca;
}

int pro()
{
	for(int i=2;i<5;++i){
		w[i].pb(1);
		w[1].pb(i);
	}
	cin>>n;
	n=2*n+4;
	for(pot=1;pot<=2*n;)pot*=2;
	RE(i,2*pot)tr[i]=inf;
	int li;
	for(int i=5;i<=n;++i){
		if(i&1)cin>>li;
		w[i].pb(li);
		w[li].pb(i);
	}
	akt=pot+1;
	dfs(1);
	for(int i=pot-1;i;--i)tr[i]=min(tr[2*i],tr[2*i+1]);
	int sr=0,e1=1,e2=1;
	for(int i=2;i<=n;++i){
		int v=i;
		if(odl(v,e1)>sr){
			sr++;
			e2=v;
		}
		swap(e1,e2);
		if(odl(v,e1)>sr){
			sr++;
			e2=v;
		}
		if(i>4 && i%2==0)cout<<sr<<"\n";
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