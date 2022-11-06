#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
const int inf=1e9;
char s[N];ll a[26][26],v[26];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n){
		rep(j,0,25)a[s[i]-'a'][j]+=v[j];
		++v[s[i]-'a'];
	}ll ans=0;
	rep(i,0,25)rep(j,0,25)ans=max(ans,a[i][j]);
	rep(i,0,25)ans=max(ans,v[i]);
	printf("%lld\n",ans);
}