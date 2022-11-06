#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 2000000
#define ll long long
#define mo 998244353
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,k,x,y,tot,ans,rt,a[N],s[N],f[N];
vector<int>p[N];
void dp(int x){
	if(p[x].size()==1){a[x]=1;return;}
	for(auto i:p[x])if(i!=f[x]){f[i]=x;dp(i);}tot=0;
	for(auto i:p[x])if((i!=f[x])&&a[i])s[++tot]=a[i];
	if(!tot)return;sort(s+1,s+tot+1);
	if(s[1]>k){
		ans+=tot;return;
	}
	dep(i,tot,1)if(s[i]+s[i-1]<=k){
		a[x]=s[i]+1;break;
	}else ans++;
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	rep(i,1,n)if(p[i].size()>1){rt=i;break;}
	dp(rt);printf("%d",ans+(a[rt]>0));
}