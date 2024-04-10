#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e5+1;
const int mg=500;
int n,m;
int a[N];
int f[N];
int mp[N];
vector<int>v[N];
int mx=0;
void add(int id){
	mp[f[a[id]]]--;
	f[a[id]]++;
	mp[f[a[id]]]++;
	if(mp[mx+1]>0) mx++;
}
void rmv(int id){
	mp[f[a[id]]]--;
	f[a[id]]--;
	mp[f[a[id]]]++;
	if(mp[mx]==0) mx--;
}
bool check(){
	return mp[mx]>=2;
}
int ans=0;
int ff[2*N];
void solve(int u,int v){
	int cur=n;
	for(int i=0; i<=2*n ;i++) ff[i]=1e9;
	ff[n]=0;
	for(int i=1; i<=n ;i++){
		if(a[i]==u) cur++;
		if(a[i]==v) cur--;
		if(ff[cur]==1e9) ff[cur]=i;
		else ans=max(ans,i-ff[cur]);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		v[a[i]].push_back(i);
		f[a[i]]++;
	}
	int x=0;
	for(int i=1; i<=n ;i++) if(f[i]>f[x]) x=i;
	for(int i=1; i<=n ;i++){
		if(i==x) continue;
		if(f[i]==f[x]) return cout << n << '\n',0;
	}
	v[x].push_back(n+1);
	reverse(v[x].begin(),v[x].end());
	v[x].push_back(0);
	reverse(v[x].begin(),v[x].end());
	for(int i=1; i<=n ;i++){
		if(i==x) continue;
		if(v[i].size()>mg) solve(i,x);
	}
	for(int i=2; i<=min(mg+10,(int)v[x].size()) ;i++){
		int l=1,r=0;
		for(int i=1; i<=n ;i++) f[i]=0,mp[i]=0;
		mp[0]=n;
		mx=0;
		for(int j=i; j<v[x].size() ;j++){
			while(r<v[x][j]-1) add(++r);
			while(l<v[x][j-i]+1) rmv(l++);
			if(check()) ans=max(ans,r-l+1);
		}
	}
	cout << ans << endl;
}