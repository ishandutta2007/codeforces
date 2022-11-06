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
char s[N];bool v[N];vector<int>p[N];
int q(int l,int r,int m=0){int tot=0;
	if(l>r)return -inf;
	rep(i,l,r)if(i!=m)tot+=p[i].size();
	printf("? %d",tot);
	rep(i,l,r)if(i!=m)for(auto&j:p[i])printf(" %d",j);
	printf("\n");fflush(stdout);
	scanf("%d",&tot);return tot;
}
void sol(){int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,k)p[i].clear();
	rep(i,1,k){int m;
		scanf("%d",&m);
		rep(j,1,m){int x;
			scanf("%d",&x);p[i].push_back(x);
		}
	}
	printf("? %d",n);
	rep(i,1,n)printf(" %d",i);
	printf("\n");fflush(stdout);
	int mx;scanf("%d",&mx);
	int l=1,r=k,m=(l+r)>>1;
	for(;l<r;m=(l+r)>>1){
		int x=q(l,m);
		if(x==mx)r=m;else l=m+1;
	}
	printf("? %d",n-int(p[m].size()));
	rep(i,1,n)v[i]=1;
	for(auto&i:p[m])v[i]=0;
	rep(i,1,n)if(v[i])printf(" %d",i);
	printf("\n");fflush(stdout);
	int t;scanf("%d",&t);
	printf("!");
	rep(i,1,m-1)printf(" %d",mx);
	printf(" %d",t);
	rep(i,m+1,k)printf(" %d",mx);
	printf("\n");fflush(stdout);
	scanf("%s",s);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}