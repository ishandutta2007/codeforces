#include<cstdio>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
using namespace std;
int n,L[N],R[N],s[N],t[N],h[N],rk[N],tt[N],tm[N],nw[N];
long long ans;char S[N];
int main(){
	scanf("%s",S);n=strlen(S);
	rep(i,1,n)s[i]=S[i-1]-'a'+1;
	rep(i,1,n)t[s[i]]++;
	rep(i,2,26)t[i]+=t[i-1];
	rep(i,1,n)rk[i]=t[s[i]];
	rep(o,0,16){
		rep(i,0,n)t[i]=0;
		rep(i,1,n)t[rk[i+(1<<o)]]++;
		rep(i,1,n)t[i]+=t[i-1];
		rep(i,1,n)tm[i]=t[rk[i+(1<<o)]];
		rep(i,0,n)nw[i]=i;
		dep(i,n,1)tt[nw[tm[i]]--]=i;
		rep(i,0,n)t[i]=0,nw[i]=0;
		rep(i,1,n)t[rk[i]]++;
		rep(i,1,n)t[i]+=t[i-1];
		dep(i,n,1){int TT=rk[tt[i]];
			if(nw[TT]&&tm[tt[i]]<nw[TT])t[TT]--;
			nw[TT]=tm[tt[i]];tm[tt[i]]=t[TT];
		}
		rep(i,1,n)rk[i]=tm[i];
	}
	rep(i,1,n)tt[rk[i]]=i;
	while(s[h[rk[1]]+1]==s[tt[rk[1]+1]+h[rk[1]]])h[rk[1]]++;
	rep(i,2,n){
		if(h[rk[i-1]])h[rk[i]]=h[rk[i-1]]-1;else h[rk[i]]=0;
		while(s[h[rk[i]]+i]==s[tt[rk[i]+1]+h[rk[i]]])h[rk[i]]++;
	}
	rep(i,1,n-1)for(L[i]=i-1;h[L[i]]>h[i];)L[i]=L[L[i]];
	dep(i,n-1,1)for(R[i]=i+1;R[i]<n&&h[R[i]]>=h[i];)R[i]=R[R[i]];
	rep(i,1,n-1){long long x=h[L[i]];
		if(h[R[i]]>x)x=h[R[i]];x=h[i]-x;
		ans+=x*(R[i]-L[i])*(R[i]-L[i]+1)/2;
	}
	rep(i,1,n){int x=h[rk[i]-1];
		if(x<h[rk[i]])x=h[rk[i]];
		ans+=n-i+1-x;
	}
	printf("%I64d\n",ans);
}