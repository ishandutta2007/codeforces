#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n;
char s[N],t[N];
ll ans,a[N];
void dfs(int u,int tp){
	if(!ans)return;
	if(tp){
		if(tp==1){
			if(s[u+1]=='9')dfs(u+1,-1);
			++s[u],++s[u+1];	
		}
		else{
			if(s[u+1]=='0')dfs(u+1,1);
			--s[u],--s[u+1];
		}
		if(ans){
			cout<<u<<' '<<tp<<'\n';
			--ans;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>(s+1)>>(t+1);
	for(int i=1;i<=n;++i){
		a[i]=-a[i-1]+s[i]-t[i];
		ans+=llabs(a[i]);
	}
	if(a[n]){
		cout<<-1<<'\n';
		return 0;	
	}
	cout<<ans<<'\n';
	ans=min(ans,100000LL);
	for(int i=1;i<=n&&ans;++i){
		while(s[i]>t[i]&&ans)dfs(i,-1);
		while(s[i]<t[i]&&ans)dfs(i,1);	
	}
	return 0;
}