#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e5+1,M=1e5+1;
#define fi first
#define se second
int n,m;
int a[N];
pair<int,int>b[N];
pair<int,int>c[N];
int p[N];
int ans[M];
vector<pair<pair<int,int>,int> >cal[262144];
vector<pair<pair<int,int>,int> >upd[262144];
vector<int>v;
void solve(int id,int l,int r){
	for(auto cur:cal[id]){
		int ql=cur.fi.se-cur.fi.fi+1,qr=cur.fi.se;
		if(l>qr || r<ql) continue;
		if(ql<=l && r<=qr) upd[id].push_back(cur);
		else{
			cal[id*2].push_back(cur);
			cal[id*2+1].push_back(cur);
		}
	}
	cal[id].clear();cal[id].shrink_to_fit();
	if(l!=r){
		int mid=(l+r)/2;
		solve(id*2,l,mid);
		solve(id*2+1,mid+1,r);
		merge(b+l,b+mid+1,b+mid+1,b+r+1,c+l);
		for(int i=l; i<=r ;i++) b[i]=c[i];
	}
	else b[l]={a[l],l};
	v.clear();
	for(int i=r; i>=l ;i--){
		int x=b[i].se;
		int px=p[r]-p[x]+a[x]*(x-l+1);
		while(v.size()>0){//better at time 0
			int j=v.back();
			if(p[r]-p[j]+a[j]*(j-l+1)>px) v.pop_back();
			else break;
		}
		while(v.size()>1){//cht
			int k=v.back(),j=v[v.size()-2];
			int pj=p[r]-p[j]+a[j]*(j-l+1),pk=p[r]-p[k]+a[k]*(k-l+1);
			if(1LL*(pk-pj)*(a[k]-a[x])>=1LL*(px-pk)*(a[j]-a[k])) v.pop_back();
			else break;
		}
		v.push_back(x);
	}
	int z=0;
	for(auto cur:upd[id]){
		//cout << cur.se << ' ' << id << ' ' << l << ' ' << r << endl;
		int x=cur.fi.fi,y=cur.fi.se;
		while(z+1<v.size()){
			int cz=(p[y]-p[v[z]]+a[v[z]]*(x-(y-v[z])));
			int cn=(p[y]-p[v[z+1]]+a[v[z+1]]*(x-(y-v[z+1])));
			if(cz>cn) z++;
			else break;
		}
		//cout << x << ' ' << y << ' ' << v[z] << endl;
		//cout << p[y]-p[v[z]]+a[v[z]]*(x-(y-v[z])) << endl;
		ans[cur.se]=min(ans[cur.se],(p[y]-p[v[z]]+a[v[z]]*(x-(y-v[z]))));
	}
}
bool cmp(pair<pair<int,int>,int> u,pair<pair<int,int>,int> v){
	return u.fi.fi-u.fi.se<v.fi.fi-v.fi.se;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];p[i]=p[i-1]+a[i];
	}
	cin >> m;
	for(int i=1; i<=m ;i++){
		int x,y;cin >> x >> y;
		cal[1].push_back({{x,y},i});
		ans[i]=2e9;
	}
	sort(cal[1].begin(),cal[1].end(),cmp);
	solve(1,1,n);
	for(int i=1; i<=m ;i++) cout << ans[i] << '\n';
}