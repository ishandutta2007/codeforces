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
#define deb(x) cerr<<#x<<" = "<<(x)<<"\n"
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}
const int inf=1e9+5,nax=1e6+5;

char rodz[25];
int id[25];
int res[2*nax];

int cob(int a){
	if(a) return(a%2?1:0)+cob(a/2);
	return 0;
}

int pro()
{
	int n;cin>>n;
	vi w;
	RI(_,n){
		int a;cin>>a;
		w.pb(a);
	}
	sort(all(w));
	reverse(all(w));
	cin>>n;
	RE(i,n)cin>>rodz[i]>>id[i];
	RE(m,1<<n)if(m){
		int jed=cob(m),zer=n-jed;
		if(id[zer]==1){
			res[m]=-inf;
			if(rodz[zer]=='p'){
				RE(i,n)if(m&(1<<i))
					maxi(res[m],res[m^(1<<i)]+w[i]);
			}
			else RE(i,n)if(m&(1<<i))
				maxi(res[m],res[m^(1<<i)]);
		}
		else{
			res[m]=inf;
			if(rodz[zer]=='p'){
				RE(i,n)if(m&(1<<i))
					mini(res[m],res[m^(1<<i)]-w[i]);
			}
			else RE(i,n)if(m&(1<<i))
				mini(res[m],res[m^(1<<i)]);
		}
	}
	cout<<res[(1<<n)-1];
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