#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mo=1e9+7;
int f[N],s[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)s[i]=1,f[i]=i;
	rep(i,1,m){int k,x,y;
		scanf("%d",&k);
		if(!k)continue;
		scanf("%d",&x);
		while(--k){
			y=x;scanf("%d",&x);
			if(gf(x)!=gf(y)){
				s[f[x]]+=s[f[y]];
				f[f[y]]=f[x];
			}
		}
	}
	rep(i,1,n)printf("%d ",s[gf(i)]);
}