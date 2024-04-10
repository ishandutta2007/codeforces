#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
#define fi first
#define se second
const int N=1001;
const ll mod=998244353;
int n,m;
ll st[2001][2048];
ll a[N],b[N];
bool ia[N],ib[N];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
inline void pull(int t,int id){
	ll duh=gcd(st[t][id*2],st[t][id*2+1]);
	st[t][id]=(st[t][id*2]/duh)*st[t][id*2+1];
}
void upd(int t,int id,int l,int r,int p,ll v){
	if(l==r){
		st[t][id]=1;return;
	}
	int mid=(l+r)/2;
	if(p<=mid) upd(t,id*2,l,mid,p,v);
	else upd(t,id*2+1,mid+1,r,p,v);
	pull(t,id);
}
void build(int t,int id,int l,int r){
	if(l==r){
		if(t<=n) st[t][id]=gcd(a[t],b[l]);
		else st[t][id]=gcd(a[l],b[t-n]);
		return;
	}
	int mid=(l+r)/2;
	build(t,id*2,l,mid);
	build(t,id*2+1,mid+1,r);
	pull(t,id);
}
void in(int& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
void in(ll& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
void out(ll& x){
	string s;
	while(x>0){
		s+=(char)('0'+x%10);
		x/=10;
	}
	reverse(s.begin(),s.end());
	cout << s;
}
void solve(){
	in(n);in(m);
	for(int i=1; i<=n ;i++){
		in(a[i]);ia[i]=true;
	}
	for(int i=1; i<=m ;i++){
		in(b[i]);ib[i]=true;
	}
	for(int i=1; i<=n ;i++){
		build(i,1,1,m);
	}
	for(int i=1; i<=m ;i++){
		build(n+i,1,1,n);
	}
	bool done=false;
	while(!done){
		done=true;
		for(int i=1; i<=n ;i++){
			if(!ia[i]) continue;
			if(st[i][1]!=a[i]){
				done=false;
				ia[i]=false;
				for(int j=1; j<=m ;j++) upd(n+j,1,1,n,i,1);
			}
		}
		for(int i=1; i<=m ;i++){
			if(!ib[i]) continue;
			if(st[n+i][1]!=b[i]){
				done=false;
				ib[i]=false;
				for(int j=1; j<=n ;j++) upd(j,1,1,m,i,1);
			}
		}
	}
	int ca=0,cb=0;
	for(int i=1; i<=n ;i++) ca+=ia[i];
	for(int i=1; i<=m ;i++) cb+=ib[i];
	if(ca==0 || cb==0){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << ca << ' ' << cb << '\n';
	for(int i=1; i<=n ;i++){
		if(ia[i]){
			out(a[i]);cout << ' ';
		}
	}
	cout << '\n';
	for(int i=1; i<=m ;i++){
		if(ib[i]){
			out(b[i]);cout << ' ';
		}
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;in(t);while(t--) solve();
}