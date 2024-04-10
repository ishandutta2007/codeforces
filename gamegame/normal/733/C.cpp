#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
ll a[501];
int m;
ll b[501];
ll sum=0;
vector<pair<int,char> >v;
bool solve(int l,int r,int x){
	if(l==r) return true;
	int mx=l;
	for(int i=l; i<=r ;i++){
		if(a[i]>a[mx]) mx=i;
		else if(a[i]==a[mx]){
			if(i!=l && a[i-1]!=a[mx]) mx=i;
			if(i!=r && a[i+1]!=a[mx]) mx=i;
		}
	}
	bool ok1=false,ok2=false;
	if(mx!=l && a[mx-1]!=a[mx]) ok1=true;
	if(mx!=r && a[mx+1]!=a[mx]) ok2=true;
	if(ok1){
		for(int i=mx-1; i>=l ;i--) v.push_back({x+i-l+1,'L'});
		for(int i=mx+1; i<=r ;i++) v.push_back({x,'R'});
		//cout << "HIJO" << endl;
		return true;
	}
	//cout << "DUH" << endl;
	if(!ok2) return false;
	for(int i=mx+1; i<=r ;i++) v.push_back({x+mx-l,'R'});
	for(int i=mx-1; i>=l ;i--) v.push_back({x+i-l+1,'L'});
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		sum+=a[i];
	}
	cin >> m;
	for(int i=1; i<=m ;i++){
		cin >> b[i];
		sum-=b[i];
	}
	if(sum!=0) return cout << "NO\n",0;
	int l=0,r=0;
	for(int i=1; i<=m ;i++){
		sum+=b[i];
		l=r+1;
		while(sum>0){
			sum-=a[++r];
		}
		if(sum<0) return cout << "NO\n",0;
		if(!solve(l,r,i)) return cout << "NO\n",0;
	}
	cout << "YES\n";
	for(auto cur:v){
		cout << cur.fi << ' ' << cur.se << '\n';
	}
}