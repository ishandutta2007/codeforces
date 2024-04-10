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

int d,m,n,x[25],a[30005];
vector<ll>ok;
ll L,R;

map<ll,vector<ll> >ans;
map<ll,vector<ll> >zip;
vector<ll>calc(ll lim){
	//0,...,lim0,...,m-1
	if(zip.find(lim) != zip.end()) return zip[lim];
	vector<ll>ret(m,0);
	if(lim == 0){
		ret[0] = 1;
		return ret;
	}
	for(int beg=0;beg<d && beg<=lim;beg++){
		ll nxt_lim = (lim-beg) / d;
		//beg, beg+d, ... , beg+nxt_lim*d
		vector<ll>R = calc(nxt_lim);
		rep(i,m){
		    int a = (i+x[beg]);
		    if(a >= m) a-=m;
			ret[a] += R[i];
		}
	}
	return zip[lim] = ret;
}
//0,....,lim
//maskmask
// /d d
//mask.size() = 10,...,limmaskdp
void rec(ll lim,vector<ll>mask,bool F){
	if(mask.size() == 1){
		if(ans.find(lim) == ans.end()){
			ans[lim] = vector<ll>(m,0);
		}
		for(int i=0;i<m;i++){
			if(((mask[0]>>i)&1LL)){
				if(F) ans[lim][i]++;
				else ans[lim][i]--;
			}
		}
		return ;
	}
	//mod d 
	for(int beg=0;beg<d && beg<=lim;beg++){
		ll nxt_lim = (lim-beg) / d;
		vector<ll>vec;
		int zan = mask.size();
		int bb = (d-beg);
		int xx = 1+(zan-bb+d-1)/d;
		vec.resize(xx,0LL);
		ll B = (1LL<<m)-1;
		int cur = beg;
		int id = 0;
		for(int i=0;i<mask.size();i++){
			int add = x[cur];
			//need + add mask[i]
			ll nw = 0;
			nw = (mask[i]>>add) | (mask[i]<<(m-add));
			B &= nw;
			if(cur == d-1 || i == mask.size()-1){
				vec[id++] = B; //cout << B << endl;
				B = (1LL<<m)-1;
			}
			cur++;
			if(cur == d) cur = 0;
		}
		assert(id == xx);
		rec(nxt_lim,vec,F);
	}
}
int main(){
	cin>>d>>m;
	rep(i,d){
		cin>>x[i];
	}
	cin>>n;
	rep(i,n){
		cin>>a[i];
		ok.pb( (2LL<<a[i])-1LL );
	}
	cin>>L>>R; L--; R--;
	rec(R-n+1,ok,true);
	if(L-1 >= 0) rec(L-1,ok,false);
	ll ret = 0;
	for(map<ll,vector<ll> >::iterator it=ans.begin();it!=ans.end();it++){
		vector<ll>tbl = calc(it->fi);
		for(int i=0;i<m;i++){
			ret += tbl[i] * it->sc[i];
		}
	}
	cout << ret << endl;
}