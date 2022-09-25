#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'

#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound

#define rep(x,s,e) for (int x=(s)-((s)>(e));x!=(e)-((s)>(e));((s)<(e))?x++:x--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
vector<ii> al[100005];
ii arr[100005];

vector<ii> v;

void dfs(int i,int p,int a,int b){
	v.pub({a,b});
	
	for (auto [it,id]:al[i]){
		if (it==p) continue;
		dfs(it,i,a+arr[id].fi,b+arr[id].se);
		v.pub({a,b});
	}
}

struct line{
	int m,c; //describing the line
	int l,r; //describing the region it covers
	
	int eval(int x){
		return m*x+c;
	}
};

int POI(line a,line b){
	return floor((double)(a.c-b.c)/(b.m-a.m));
}

vector<line> add(vector<line> a,vector<line> b){
	vector<line> res;
	
	int i=0,j=0;
	while (i<sz(a)){
		res.pub({a[i].m+b[j].m,a[i].c+b[j].c,
					max(a[i].l,b[j].l),min(a[i].r,b[j].r)});
		
		if (a[i].r<b[j].r) i++;
		else if (b[j].r<a[i].r) j++;
		else i++,j++;
	}
	
	return res;
}

vector<line> max(vector<line> a,vector<line> b){
	vector<line> res;
	
	int i=0,j=0;
	while (i<sz(a)){
		int tl=max(a[i].l,b[j].l),tr=min(a[i].r,b[j].r);
		
		if (a[i].eval(tl)>b[j].eval(tl)){
			if (a[i].eval(tr)<b[j].eval(tr)){
				int tm=POI(a[i],b[j]);
				res.pub({a[i].m,a[i].c,tl,tm});
				res.pub({b[j].m,b[j].c,tm+1,tr});
			}
			else{
				res.pub({a[i].m,a[i].c,tl,tr});
			}
		}
		else{
			if (a[i].eval(tr)>b[j].eval(tr)){
				int tm=POI(a[i],b[j]);
				res.pub({b[j].m,b[j].c,tl,tm});
				res.pub({a[i].m,a[i].c,tm+1,tr});
			}
			else{
				res.pub({b[j].m,b[j].c,tl,tr});
			}
		}
		
		if (a[i].r<b[j].r) i++;
		else if (b[j].r<a[i].r) j++;
		else i++,j++;
	}
	
	vector<line> res2;
	for (auto it:res){
		if (res2.empty() || res2.back().m!=it.m || res2.back().c!=it.c) res2.pub(it);
		else res2.back().r=it.r;
	}
	
	return res2;
}

struct dat{
	vector<line> a,b,c;
	vector<line> ab,bc;
	vector<line> abc;
	 
	dat (){}
	dat (int M,int C){
		a=c={{M,C,0,k-1}};
		b={{-2*M,-2*C,0,k-1}};
		ab=bc={{-M,-C,0,k-1}};
		abc={{0,0,0,k-1}};
	}
};

dat merge(dat u,dat v){
	dat res;
	
	res.a=max(u.a,v.a);
	res.b=max(u.b,v.b);
	res.c=max(u.c,v.c);
	res.ab=max(max(u.ab,v.ab),add(u.a,v.b));
	res.bc=max(max(u.bc,v.bc),add(u.b,v.c));
	res.abc=max(max(u.abc,v.abc),max(add(u.ab,v.c),add(u.a,v.bc)));
	
	return res;
}

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>n>>k;
	
	rep(x,1,n){
		int a,b;
		cin>>a>>b>>arr[x].fi>>arr[x].se;
		al[a].pub({b,x});
		al[b].pub({a,x});
	}
	
	dfs(1,-1,0,0);
	
	//for (auto [a,b]:v) cout<<a<<" "<<b<<endl;
	
	vector<dat> lines;
	rep(x,0,sz(v)) lines.pub({v[x].fi,v[x].se});
	
	while (sz(lines)>=2){
		vector<dat> temp;
		
		for (int x=0;x<sz(lines);x+=2){
			if (x+1<sz(lines)) temp.pub(merge(lines[x],lines[x+1]));
			else temp.pub(lines[x]);
		}
		swap(lines,temp);
	}
	
	vector<line> fin=lines[0].abc;
	
	for (auto it:fin) rep(x,it.l,it.r+1) cout<<it.eval(x)<<" "; cout<<endl;
}