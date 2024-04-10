#include<bits/stdc++.h>
#define id(x) (1ll*k*s[x]-x+n)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+2,INF=N*sqrt(N);
char a[N];long long ans;
int n,p,l,r,lim,s[N],L[N],R[N],mp[INF];
int main(){
	scanf("%s",a+1),n=strlen(a+1),lim=sqrt(n);
	FOR(i,1,n)s[i]=s[i-1]+a[i]-48;
	FOR(i,0,n)(s[i]&&!L[s[i]])&&(L[s[i]]=i),R[s[i]]=i;
	FOR(k,1,lim){
		FOR(i,0,n)ans+=mp[id(i)]++;
		FOR(i,0,n)mp[id(i)]=0;
	}
	FOR(k,1,lim){
		FOR(i,0,n){
			while(s[i]-s[p]>lim)mp[id(p)]--,p++;
			ans-=mp[id(i)]++;
		}
		FOR(i,0,n)mp[id(i)]=0;p=0;
	}
	FOR(i,1,n)FOR(k,1,lim)if(k<=s[i]){
		l=L[s[i]-k],r=R[s[i]-k];
		if(~l&&~r)ans+=(r-i%k+k)/k-(l-i%k+k-1)/k;
	}
	std::cout<<ans;
}