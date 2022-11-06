#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
char s[N];int s0[N],s1[N];
void sol(){
	scanf("%s",s+1);
	int n=strlen(s+1),ans=n;
	rep(i,1,n){
		s0[i]=s0[i-1]+(s[i]=='0');
		s1[i]=s1[i-1]+(s[i]=='1');
	}int t0=0,t1=0;
	dep(i,n,1){
		ans=min(ans,min(s0[i]+t1,s1[i]+t0));
		t0+=s[i]=='0';
		t1+=s[i]=='1';
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}