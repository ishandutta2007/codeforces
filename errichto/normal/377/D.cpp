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
const int inf=1e9+5,nax=1e6+5,pot=1<<19;

int a[nax],b[nax],c[nax],tr[2*pot+5],res[2*pot+5];

bool cmpa(int s, int d){return a[s]<a[d];}
bool cmpb(int s, int d){return b[s]<b[d];}

void fop(int d,int ile){
	for(int i=pot+d;i;i/=2){
		if(i%2){
			tr[i-1]+=ile;
			res[i-1]+=ile;
		}
		if(i<pot)res[i]=tr[i]+max(res[2*i],res[2*i+1]);
	}
}

void prze(int l, int r, int ile){
	fop(r+1,ile);
	fop(l,-ile);
}

int tu(){
	int i=1;
	while(i<pot)
		res[2*i]>res[2*i+1] ? i=2*i : i=2*i+1;
	return i-pot;
}

int pro()
{
	int n;
	cin>>n;
	RE(i,n)cin>>a[i]>>b[i]>>c[i];
	vi B,A;
	RE(i,n)A.pb(i);
	B=A;
	sort(all(A),cmpa);
	sort(all(B),cmpb);
	int akt=0;
	pair<int,pii > r=mp(0,mp(0,0));
	RE(i,n){
		int id=B[i];
		while(akt<n && a[A[akt]]<=b[id]){
			prze(b[A[akt]],c[A[akt]],1);
			akt++;
		}
		maxi(r,mp(res[1],mp(b[id],tu())));
		prze(b[id],c[id],-1);
	}
	cout<<r.x<<"\n";
	int low=r.y.x,high=r.y.y;
	deb(low);deb(high);
	RE(i,n)if(a[i]<=low && low<=b[i] && b[i]<=high && high<=c[i])cout<<i+1<<" ";
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