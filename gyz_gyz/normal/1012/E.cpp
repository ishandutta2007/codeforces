#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,k,tot,x,ans,a[N],b[N],f[N],ed[N],nt[N],nm[N],ss[N];
map<int,int>mp,rw;bool v[N];
int gf(int x){
	if(f[x]==x)return x;
	f[x]=gf(f[x]);return f[x];
}
int main(){
	scanf("%d %d",&n,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);b[i]=a[i];
	}
	sort(b+1,b+n+1);
	rep(i,1,n)if(b[i]!=b[i-1])mp[b[i]]=i;
	rep(i,1,n)if(a[i]!=b[i])k--;else v[i]=1;
	rep(i,1,n)for(;v[mp[b[i]]];mp[b[i]]++){
		if(b[mp[b[i]]]!=b[i]){mp[b[i]]=0;break;}
	}
	if(k<0){printf("-1");return 0;}
	rep(i,1,n)if(!v[i]){tot++;
		for(x=i;x;x=mp[a[x]]){
			for(mp[b[x]]++;v[mp[b[x]]];mp[b[x]]++){
				if(b[mp[b[x]]]!=b[x]){mp[b[x]]=0;break;}
			}
			if(b[mp[b[x]]]!=b[x])mp[b[x]]=0;v[x]=1;
			if(ed[tot]){
				nt[ed[tot]]=x;f[x]=f[ed[tot]];
			}else f[x]=x;
			ed[tot]=x;nm[f[x]]++;
		}
		nt[ed[tot]]=f[ed[tot]];
	}
	rep(i,1,n)if(a[i]!=b[i]){
		if(rw[a[i]]){
			if(gf(i)!=gf(rw[a[i]])){
				nm[f[rw[a[i]]]]+=nm[f[i]];
				f[f[i]]=f[rw[a[i]]];
				swap(nt[i],nt[rw[a[i]]]);
			}
		}else rw[a[i]]=i;
	}tot=0;
	rep(i,1,n)if((a[i]!=b[i])&&(gf(i)==i))ss[++tot]=i;
	if((tot>2)&&(k>2)){
		ans=tot-min(tot,k)+1;x=nt[ss[ans]];
		rep(i,ans+1,tot){
			nt[ss[i-1]]=nt[ss[i]];nm[ss[ans]]+=nm[ss[i]];
		}
		nt[ss[tot]]=x;
	}else ans=tot;
	if(ans<tot)printf("%d\n",ans+1);else printf("%d\n",ans);
	rep(i,1,ans){
		printf("%d\n",nm[ss[i]]);
		for(x=ss[i];nt[x]!=ss[i];x=nt[x])printf("%d ",x);
		printf("%d\n",x);
	}
	if(ans<tot){
		printf("%d\n",tot-ans+1);
		dep(i,tot,ans)printf("%d ",nt[ss[i]]);
	}
}