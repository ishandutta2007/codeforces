#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,N=1e5;
const ll inf=9e18,M=1e12;
int n;
ll a[N+5];
char b[N+5];
mt19937_64 rng(time(0));
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	scanf("%s",b+1);
	ll t=0,cnt[10]={0};
	for(int i=1;i<=n;i++){
		if(b[i]=='L'){
			t+=a[i];
			ll w=a[i];
			for(int j=1;j<=5;j++){
				if(cnt[j]){
					ll u=min(w,cnt[j]);
					t+=j*u,w-=u,cnt[j]-=u;
				}
			}
		}
		if(b[i]=='G'){
			cnt[5]=inf;
			ll w=a[i],u=min(w,cnt[1]);
			w-=u,cnt[1]-=u,t+=u;//u
			t+=u;//u 
			t+=3*(a[i]-u);
			cnt[2]+=a[i]+u;
		}
		if(b[i]=='W'){
			cnt[3]=inf;
			t+=2*a[i];
			cnt[1]+=a[i];
		}
		//cout<<i<<' '<<t<<'\n';
	}
	cout<<t;
}