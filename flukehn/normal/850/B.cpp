#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
const int N=1e6+11,M=1e6;
typedef long long ll;
const ll inf=LONG_LONG_MAX;
int c[N*2],n;
ll ct[N*2],x,y,ans=inf;
int T;
void work(){
	ll now=0;
	rep(i,2,M){
		now=0;
		for(int j=i;j<=M+i;j+=i){
			int k=max(j-i+1,j-T);
			now+=y*((c[j]-c[k-1])*1LL*j-ct[j]+ct[k-1]);
			now+=x*(c[k-1]-c[j-i]);
			if(now>=ans)break;
		}
		ans=min(ans,now);
	}
}/*
for (i=2; i<=1000000; i++){
		ll tmp=0;
		for (j=i; j<=1000000+i && tmp<ans; j+=i){
			k=max(j-i+1,j-p);
			tmp+=((a[j]-a[k-1])*j - (s[j]-s[k-1]))*B;
			tmp+=(ll)(a[k-1]-a[j-i])*A;
		}
		ans=min(ans,tmp);
	}
*/
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>x>>y;
	T=x/y;
	rep(i,1,n){
		int x;
		cin>>x;
		c[x]++;
		ct[x]+=x;
	}
	rep(i,1,2*M)c[i]+=c[i-1];
	rep(i,1,2*M)ct[i]+=ct[i-1];
	work();
	cout<<ans<<endl;
}