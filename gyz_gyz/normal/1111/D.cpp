#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define gc getchar()
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int w[55],r[55][55],ch[300],a[N],b[N];
char s[N];ll p[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){p[0]=1;
	scanf("%s",s+1);int n=strlen(s+1);
	rep(i,1,n)p[i]=p[i-1]*i%mo;
	ll ct=p[n/2]*p[n/2]*2%mo;
	rep(i,'a','z')ch[i]=i-'a'+1;
	rep(i,'A','Z')ch[i]=i-'A'+27;
	rep(i,1,n)++w[ch[s[i]]];
	rep(i,1,52)ct=ct*qk(p[w[i]],mo-2)%mo;
	rep(i,1,52){
		rep(j,1,n/2)a[j]=0;a[0]=1;
		rep(j,1,52)if(i!=j&&w[j])dep(k,n/2,w[j])a[k]=(a[k]+a[k-w[j]])%mo;
		r[i][i]=a[n/2];
		rep(j,i+1,52){
			if(w[j]){
				rep(k,0,w[j]-1)b[k]=a[k];
				rep(k,w[j],n/2)b[k]=(a[k]+mo-b[k-w[j]])%mo;
				r[i][j]=r[j][i]=b[n/2];
			}else r[i][j]=r[j][i]=b[n/2];
		}
	}int m;
	scanf("%d",&m);
	while(m--){int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",r[ch[s[x]]][ch[s[y]]]*ct%mo);
	}
}