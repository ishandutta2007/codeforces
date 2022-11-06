#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 300010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,tot,ans,nw,a[N],l[N],r[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		a[x]=max(a[x],y+1);
	}
	rep(i,1,n){
		if(a[i]>nw){
			nw=a[i];l[++tot]=i;r[tot]=nw;
		}
		if(nw>i)++ans;
	}
	if(m-tot>1)return printf("%d\n",ans),0;
	l[tot+1]=n+1;
	if(m>tot){int s=ans;
		rep(i,1,tot)s=min(s,min(r[i],l[i+1])-max(l[i],r[i-1]));
		return printf("%d\n",ans-max(s,0)),0;
	}int s=ans;
	rep(i,1,tot-1){ 
		s=min(s,max(min(r[i],l[i+1])-max(l[i],r[i-1]),0)+max(min(r[i+1],l[i+2])-max(l[i+1],r[i-1]),0));
		rep(j,i+2,tot)s=min(s,max(min(r[i],l[i+1])-max(l[i],r[i-1]),0)+max(min(r[j],l[j+1])-max(l[j],r[j-1]),0));
	}
	printf("%d\n",ans-s);
}