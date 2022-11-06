#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=998244353;
int n;vector<int>ans;string s;
void sol(int m){
	vector<int>res(n);
	rep(i,0,m-1)res[i+n-m]=s[i]-'0';
	dep(i,n-1,m){
		res[i]+=s[i]-'0';
		if(res[i]>9)res[i]-=10,++res[i-1];
	}
	dep(i,m-1,0){
		if(res[i]<=9)break;
		res[i]-=10;++res[i-1];
	}
	rep(i,0,n-1){
		if(res[i]<ans[i]){
			ans=res;return;
		}
		if(ans[i]<res[i])return;
	}
}
int main(){
	cin>>n>>s;bool fl=0;
	for(auto &i:s)ans.pb(i-'0');
	int l=n/2,r=n-n/2;
	while(~l&&s[l]=='0')--l;
	while(r<n&&s[r]=='0')++r;
	if(~l)sol(l);
	if(r<n)sol(r);
	rep(i,0,n-1){
		if(ans[i])fl=1;
		if(fl)printf("%d",ans[i]);
	}
}