#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
map<int,ll> ans;
vector<pair<int,int> > val[2];
int n,m;
int a[N];
inline int _gcd(int a,int b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
void solve(int l,int r){
	if(l==r){
		ans[a[l]]++;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	val[0].clear(),val[1].clear();
	int las=a[mid],now=a[mid],cnt=0;
	for(int i=mid;i>=l;i--){
		now=_gcd(now,a[i]);
		if(now!=las){
			val[0].push_back(make_pair(las,cnt));
			las=now,cnt=1;
		}
		else ++cnt;
	}
	val[0].push_back(make_pair(las,cnt));
	las=now=a[mid+1],cnt=0;
	for(int i=mid+1;i<=r;i++){
		now=_gcd(now,a[i]);
		if(las!=now){
			val[1].push_back(make_pair(las,cnt));
			las=now,cnt=1;
		}
		else ++cnt;
	}
	val[1].push_back(make_pair(las,cnt));
	for(int i=0;i<val[0].size();i++){
		for(int j=0;j<val[1].size();j++){
			ans[_gcd(val[0][i].first,val[1][j].first)]+=1LL*val[0][i].second*val[1][j].second;
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	solve(1,n);
	m=read();
	for(int i=1;i<=m;i++){
		int x=read();
		cout<<ans[x]<<endl;
	}
	return 0;
}