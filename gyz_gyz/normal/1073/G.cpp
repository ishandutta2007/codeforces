#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,q,t,k,l,rk[N],sa[N],lcp[N][18],tot[2],vr[26];
char s[N];ll d[N],w[N][2];pair<int,bool>a[N];
vector<int>v1[N];vector<pair<int,int>>v2[N];
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	rep(i,1,n)vr[s[i]-'a']=1;
	rep(i,1,25)vr[i]+=vr[i-1];
	rep(i,1,n)rk[i]=vr[s[i]-'a'];
	rep(j,0,17){
		rep(i,0,n){
			v1[i].clear();v2[i].clear();
		}
		rep(i,1,n)v1[rk[i+(1<<j)]].pb(i);int x=0;
		rep(i,0,n)for(auto k:v1[i])v2[rk[k]].pb({k,rk[k+(1<<j)]});
		rep(i,0,n){pair<int,int>ls={0,-1};
			for(auto k:v2[i]){
				if(k.sc!=ls.sc)x++;rk[k.fr]=x;ls=k;
			}
		}
	}
	rep(i,1,n)sa[rk[i]]=i;
	rep(i,1,n)for(lcp[rk[i]][0]=max(lcp[rk[i-1]][0]-1,0);
	s[i+lcp[rk[i]][0]]==s[sa[rk[i]-1]+lcp[rk[i]][0]];)lcp[rk[i]][0]++;
	rep(j,1,17)rep(i,1,n)lcp[i][j]=min(lcp[i][j-1],lcp[i+(1<<(j-1))][j-1]);
	rep(o,1,q){ll ans=0;ll tot[2]={0,0};
		scanf("%d%d",&k,&l);
		rep(i,1,k){int x;
			scanf("%d",&x);a[i]={rk[x],0};
		}
		rep(i,1,l){int x;
			scanf("%d",&x);a[i+k]={rk[x],1};
		}
		sort(a+1,a+k+l+1);t=0;int lf=a[1].fr;
		rep(i,2,k+l){
			ll x;ll al[2]={0,0};al[a[i-1].sc]=1;
			if(a[i].fr==lf)x=n-sa[a[i].fr]+1;else
			dep(j,17,0)if((a[i].fr-lf)>>j){
				x=min(lcp[lf+1][j],lcp[a[i].fr-(1<<j)+1][j]);break;
			}lf=a[i].fr;
			for(;t&&x<=d[t];t--)rep(j,0,1){
				tot[j]-=w[t][j]*d[t];al[j]+=w[t][j];
			}d[++t]=x;
			rep(j,0,1){
				w[t][j]=al[j];tot[j]+=x*al[j];
			}
			ans+=tot[a[i].sc^1];
		}
		printf("%lld\n",ans);
	}
}