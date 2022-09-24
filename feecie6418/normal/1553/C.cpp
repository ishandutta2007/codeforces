#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[15];
int ans;
void dfs(int x,int s1,int s2){
	int t1=(11-x)/2,t2=(12-x)/2;
	if(s1+t1<s2||s2+t2<s1||x==11)return ans=min(ans,x-1),void();
	if(x%2==1){
		if(a[x]=='1'||a[x]=='?')dfs(x+1,s1+1,s2);
		if(a[x]=='0'||a[x]=='?')dfs(x+1,s1,s2);
	}
	else {
		if(a[x]=='1'||a[x]=='?')dfs(x+1,s1,s2+1);
		if(a[x]=='0'||a[x]=='?')dfs(x+1,s1,s2);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ans=1e9,cin>>a+1,dfs(1,0,0),cout<<ans<<'\n';
	}
}