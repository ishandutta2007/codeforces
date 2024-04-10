#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n,m;
int a[100001];
bool iss[100001];
int p[100001];
int st;
int bit[100001];
int f[100001];
int b[100001];
bool die[100001];
void upd(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]+=v;
}
int qry(int id){
	int res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[i];
	return res;
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		iss[i]=false;
		p[a[i]]=i;
		bit[i]=0;
		die[i]=false;
		f[i]=0;
	}
	for(int i=1; i<=m ;i++){
		cin >> b[i];
		f[b[i]]=i;
	}
	int ptr=m;
	for(int i=1; i<=n ;i++){
		if(f[i]==0) f[i]=++ptr;
	}
	st=0;
	ll ans=0;
	int mj=0;
	for(int i=1; i<=m ;i++){
		if(iss[b[i]]){
			upd(i,-1);
			ans+=qry(i)*2+1;
		}
		else{
			while(++st<p[b[i]]){
				if(!die[a[st]]) upd(f[a[st]],1);
				iss[a[st]]=true;
			}
			ans+=2*p[b[i]]-1-i*2+2;
		}
		die[b[i]]=true;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		solve();
	}
}