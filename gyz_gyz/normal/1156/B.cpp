#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int a[30];bool v[30];
void sol(){
	rep(i,0,26)a[i]=0,v[i]=0;
	string s,ans;cin>>s;
	for(auto i:s)++a[i-'a'];
	bool fl=0,ok=0;
	rep(i,0,25){
		if(a[i]&&!fl&&!((!i||!a[i-1])&&!a[i+1])){
			if(ok){
				rep(j,1,a[i])ans+=i+'a';v[i]=1;fl=1;
			}else ok=1;
		}else fl=0;
	}
	rep(i,0,25)if((!i||!a[i-1])&&!a[i+1]){
		rep(j,1,a[i])ans+=i+'a';v[i]=1;
	}
	rep(i,0,25)if(!v[i])rep(j,1,a[i])ans+=i+'a';
	int n=s.length();
	rep(i,1,n-1)if(abs(ans[i]-ans[i-1])==1){
		printf("No answer\n");return;
	}
	cout<<ans<<'\n';
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}