#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<pair<int,int>,pair<ll,bool> > range;
typedef pair<pair<ll,ll>,int> query;//factor,range,boss
#define fi first
#define se second
int n,q;
set<range>bl;
vector<range>bin;
ll s[100001],m[100001],r[100001];
ll pm[100001];
ll ans[100001];
vector<query>qr[100003];
vector<query>qm[100003];
vector<int>pot[100003];
ll br[100001],bm[100001];
void upd(int id,ll v,ll* bit){
	for(int i=id; i<=1e5 ;i+=i&-i) bit[i]+=v;
}
ll qry(int id,ll* bit){
	ll res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[i];
	return res;
}
void putqr(ll f,int pos,ll lim,int boss){
	lim=min(lim,100001LL);
	qr[lim].push_back({{f,pos},boss});
}
void putqm(ll f,int pos,ll lim,int boss){
	lim=min(lim,100001LL);
	qm[lim].push_back({{f,pos},boss});
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> s[i] >> m[i] >> r[i];
		pm[i]=pm[i-1]+m[i];
		bl.insert({{i,i},{0,1}});
		if(r[i]==0) pot[100001].push_back(i);
		else pot[m[i]/r[i]].push_back(i);
	}
	cin >> q;
	for(int i=1; i<=q ;i++){
		ll t;
		int nl,nr;
		cin >> t >> nl >> nr;
		auto it=bl.lower_bound({{nl+1,0},{0,0}});
		--it;
		while(it!=bl.end()){
			if(it->fi.fi>nr) break;
			int cl=max(nl,it->fi.fi),cr=min(nr,it->fi.se);
			if(it->se.se){//yo
				ans[i]+=min(m[cl],s[cl]+r[cl]*t);
			}
			else{
				cl--;
				ll last=it->se.fi;
				ans[i]+=pm[cr]-pm[cl];
				putqm(-1,cr,t-last,i);
				putqm(1,cl,t-last,i);
				putqr(t-last,cr,t-last,i);
				putqr(last-t,cl,t-last,i);
			}
			if(it->fi.fi<nl) bin.push_back({{it->fi.fi,nl-1},it->se});
			if(it->fi.se>nr) bin.push_back({{nr+1,it->fi.se},it->se});
			bl.erase(it++);
		}
		for(auto j:bin) bl.insert(j);
		bin.clear();
		bl.insert({{nl,nr},{t,0}});
	}
	//cout << "YOLO\n";
	for(int i=1e5+1; i>=0; i--){
		for(auto id:pot[i]){
			upd(id,r[id],br);
			upd(id,m[id],bm);
		}
		for(auto cur:qr[i]){
			ll res=qry(cur.fi.se,br);
			ans[cur.se]+=cur.fi.fi*res;
		}
		for(auto cur:qm[i]){
			ll res=qry(cur.fi.se,bm);
			ans[cur.se]+=cur.fi.fi*res;
		}
	}
	for(int i=1; i<=q ;i++) cout << ans[i] << '\n';
}