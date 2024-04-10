#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e5+1;
int n;
vector<pair<ll,int> >x,y;
int cx[N],cy[N];
int z[N];

vector<int>p(3);
const int ts=262144;
int cl[ts],cr[ts];
void upd(int id,int l,int r,int ps,int c){
	if(l==r){
		if(c==p[0]) cl[id]++;
		if(c==p[1]) cr[id]++;
		return;
	}
	int mid=(l+r)/2;
	if(ps<=mid) upd(id*2,l,mid,ps,c);
	else upd(id*2+1,mid+1,r,ps,c);
	cl[id]=cl[id*2]+cl[id*2+1];
	cr[id]=cr[id*2]+cr[id*2+1];
}
bool debug=false;
int fun(int id,int l,int r,int dl,int dr){
	if(debug) cout << id << ' ' << l << ' ' << r << ' ' << dl << ' ' << dr << endl;
	if(l==r){
		return max(min(dl,dr+cr[id]),min(dl+cl[id],dr));
	}
	int mid=(l+r)/2;
	if(dl+cl[id*2]>dr+cr[id*2+1]) return fun(id*2,l,mid,dl,dr+cr[id*2+1]);
	else return fun(id*2+1,mid+1,r,dl+cl[id*2],dr);
}
void build(int id,int l,int r){
	cl[id]=cr[id]=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
}
int solve(){
	int lt=0;
	for(int i=1; i<=n ;i++){
		if(i==1 || x[i].fi!=x[i-1].fi) lt=i;
		cx[x[i].se]=lt;
	}
	lt=0;
	for(int i=1; i<=n ;i++){
		if(i==1 || y[i].fi!=y[i-1].fi) lt=i;
		cy[y[i].se]=lt;
	}
	p[0]=1;p[1]=2;p[2]=3;
	int ans=0;
	do{
		build(1,1,n);
		int c3=n/3;
		for(int i=1; i<=n ;i++){
			int w=y[i].se;
			c3-=(z[w]==p[2]);
			upd(1,1,n,cx[w],z[w]);
			int best=fun(1,1,n,0,0);
			if(i!=n && y[i+1].fi==y[i].fi);
			else ans=max(ans,min(c3,best));
		}
	}while(next_permutation(p.begin(),p.end()));
	do{
		build(1,1,n);
		int c3=n/3;
		for(int i=1; i<=n ;i++){
			int w=y[i].se;
			c3-=(z[w]==p[2]);
			upd(1,1,n,cy[w],z[w]);
			int best=fun(1,1,n,0,0);
			//cout << c3 << ' ' << best << endl;
			if(i!=n && y[i+1].fi==y[i].fi);
			else ans=max(ans,min(c3,best));
		}
		//cout << "ugh " << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
	}while(next_permutation(p.begin(),p.end()));
	//cout << ans << endl;
	//system("pause");
	return ans;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	x.resize(n+1);y.resize(n+1);
	for(int i=1; i<=n ;i++){
		cin >> x[i].fi;x[i].se=i;
		cin >> y[i].fi;y[i].se=i;
		cin >> z[i];
	}
	sort(x.begin()+1,x.begin()+n+1);sort(y.begin()+1,y.begin()+n+1);
	int ans=solve();
	for(int i=0; i<3 ;i++){
		swap(x,y);
		reverse(x.begin()+1,x.end());
		for(int j=1; j<=n ;j++) x[j].fi=-x[j].fi;
		ans=max(ans,solve());
	}
	cout << ans*3 << '\n';
}