#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,s,x;
int main(){
	cin>>n>>s>>x;
	srand((unsigned)time(NULL));
	cout<<"? "<<s<<endl;
	int a,b; cin>>a>>b;
	if(a >= x){
		cout<<"! "<<a<<endl;
		return 0;
	}
	P p = mp(a,s);
	rep(q,999){
		int v = (rand()*rand())%n;
		v = (v+n)%n+1;
		cout<<"? "<<v<<endl;
		cin>>a>>b;
		if(a >= x) continue;
		p = max(p,mp(a,v));
	}
	while(1){
		cout<<"? "<<p.sc<<endl;
		cin>>a>>b;
		if(a >= x){
			cout<<"! "<<a<<endl;
			return 0;
		}
		if(b == -1){
			cout<<"! "<<-1<<endl;
			return 0;
		}
		p.sc = b;
	}
	return 0;
}