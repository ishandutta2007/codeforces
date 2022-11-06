#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,m,s,t,ans,d[N],dl[N],fr[N],nt[N];
vector<int>p[N],q[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);q[y].pb(x);d[y]++;
	}
	rep(i,1,n)if(!d[i])dl[++t]=i;
	for(s=1;s<=t;s++){
		if(s==t)nt[dl[s]]=n-s;
		if(s+1==t){bool fl=1;
			for(auto i:p[dl[t]])if(d[i]==1){fl=0;break;}
			if(fl)nt[dl[s]]=n-s-1;
		}
		for(auto i:p[dl[s]]){
			d[i]--;if(!d[i])dl[++t]=i;
		}
	}t=0;
	rep(i,1,n)for(auto j:q[i])d[j]++;
	rep(i,1,n)if(!d[i])dl[++t]=i;
	for(s=1;s<=t;s++){
		if(s==t)fr[dl[s]]=n-s;
		if(s+1==t){bool fl=1;
			for(auto i:q[dl[t]])if(d[i]==1){fl=0;break;}
			if(fl)fr[dl[s]]=n-s-1;
		}
		for(auto i:q[dl[s]]){
			d[i]--;if(!d[i])dl[++t]=i;
		}
	}
	rep(i,1,n)if(nt[i]+fr[i]>=n-2)ans++;
	printf("%d\n",ans);
}