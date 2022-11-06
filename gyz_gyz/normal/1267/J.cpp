#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
const int N=2e6+10;
int s[N],t[N],r[N];
void sol(){int n,m=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(!t[x]){
			t[x]=++m;r[m]=x;
		}
		++s[t[x]];
	}
	int mi=n,ans=n;
	rep(i,1,m)mi=min(mi,s[i]);
	rep(i,1,mi+1){
		int tt=0;bool ok=1;
		rep(j,1,m){
			int ss=(s[j]-1)/i+1;
			if(ss*i-s[j]>ss){
				ok=0;break;
			}
			tt+=ss;
		}
		if(ok)ans=min(ans,tt);
	}
	printf("%d\n",ans);
	rep(i,1,m){
		s[i]=0;t[r[i]]=0;r[i]=0;
	}
}
int main(){
	int t;scanf("%d",&t);
	rep(i,1,t)sol();
}