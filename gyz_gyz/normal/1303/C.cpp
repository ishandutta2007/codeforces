#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
char s[N];bool v[26];
string res;set<int>p[26];
void dfs(int x){
	v[x]=1;res+=x+'a';
	for(auto&i:p[x])if(!v[i])dfs(i);
}
void sol(){
	scanf("%s",s+1);res.clear();
	int n=strlen(s+1);
	rep(i,0,25)v[i]=0,p[i].clear();
	rep(i,2,n){
		p[s[i]-'a'].insert(s[i-1]-'a');
		p[s[i-1]-'a'].insert(s[i]-'a');
	}
	rep(i,0,25)if(p[i].size()>2){
		printf("NO\n");return;
	}
	rep(i,0,25)if(!v[i]&&p[i].size()<2)dfs(i);
	rep(i,0,25)if(!v[i]){
		printf("NO\n");return;
	}
	printf("YES\n%s\n",res.c_str());
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}