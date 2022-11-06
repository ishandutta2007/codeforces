#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 300000
#define ll long long
#define pb push_back
using namespace std;
int n,x,y,f[N];ll ans,a[N],b[N],c[N];
vector<int>p[N];
void dp(int x){b[x]=1;
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;dp(i);
		ans+=a[x]*(b[i]+c[i])+a[i]*(b[x]+c[x])+b[i]*b[x];
		b[x]+=c[i];c[x]+=b[i];a[x]+=a[i]+b[i];
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	dp(1);
	printf("%I64d\n",ans);
}