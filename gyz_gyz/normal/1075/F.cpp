#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 400010
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
typedef long long ll;
using namespace std;
int n,tot,ls,f[N],s[N];map<int,int>t;
void nw(int x){
	if(!t.count(x))t[x]=++tot,f[tot]=tot;
}
void gf(int x){
	if(f[x]==x)return;
	gf(f[x]);s[x]^=s[f[x]];f[x]=f[f[x]];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		x^=ls;y^=ls;
		if(x>y)swap(x,y);y++;
		if(op==1){int z;
			scanf("%d",&z);z^=ls;
			nw(x);nw(y);x=t[x];y=t[y];gf(x);gf(y);
			if(f[x]!=f[y]){
				s[f[x]]=z^s[y]^s[x];
				f[f[x]]=f[y];
			}
		}else{
			if(!t.count(x)||!t.count(y)){
				printf("-1\n");ls=1;continue;
			}
			x=t[x];y=t[y];gf(x);gf(y);
			if(f[x]!=f[y]){
				printf("-1\n");ls=1;
			}else{
				ls=s[x]^s[y];printf("%d\n",ls);
			}
		}
	}
}