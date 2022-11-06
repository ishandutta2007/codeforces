#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,tot,f[N],r[N],s[N],t[N];ll a[N],k,ans;
int main(){
	scanf("%d%I64d",&n,&k);
	rep(i,2,n){int x;ll y;
		scanf("%d%I64d",&x,&y);a[i]=y^a[x];
	}
	sort(a+1,a+n+1);s[1]=n;
	rep(i,1,n)t[i]=f[i]=1;
	dep(j,61,0){
		ll al=0;if(!k)break;
		rep(i,1,n)if(f[i]==i)r[i]=-1;
			else if((a[i]>>j&1)^(a[i-1]>>j&1)){
				s[i]=s[f[i]]-i+f[i];s[f[i]]=i-f[i];
				r[f[i]]=i;f[i]=i;
			}else f[i]=f[i-1];
		rep(i,1,n)if(~t[i])
			if(!((a[i]>>j&1)^(a[t[i]]>>j&1)))al+=s[t[i]];
			else if(~r[t[i]])al+=s[r[t[i]]];
		if(al<k){k-=al;ans+=1ll<<j;
			rep(i,1,n)if(~t[i]&&!((a[i]>>j&1)^(a[t[i]]>>j&1)))t[i]=r[t[i]];
		}else rep(i,1,n)if(~t[i]&&(a[i]>>j&1)^(a[t[i]]>>j&1))t[i]=r[t[i]];
	}
	printf("%I64d\n",ans);
}