#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int divv[10000005],n;
ll ans[10000005];
int prr[10000005],c;
int f[256];
int main(){
	cin>>n;
	for(int i=0;i<256;i++) f[i] = __builtin_popcount(i);
	for(int i=2;i<=10000000;i++){
		if(divv[i] != 0) continue;
		if(i*2 <= n){
			prr[c++] = i;
		}
		for(int j=i*2;j<=10000000;j+=i){
			divv[j] = i;
		}
	}
	for(int i=2;i<=n;i++){
		if(divv[i] == 0){
		    if(i*2>n) continue;
		    ll x = i;
			ll y = max(x,n/x);
			int d = upper_bound(prr,prr+c,y)-prr;
			//[d,c)
			//cout<<prr[d]<<endl;
			ans[i] -= (c-d)*2; //cout<<i<<" "<<c<<" "<<d<<endl;
			ans[i] += n/i - 1;
		}
		else if(divv[i/divv[i]] == divv[i]){
			ans[i] = ans[i/divv[i]];
		}
		else{
			int pr[11];
			int nxt=0,cur=i;
			while(divv[cur] != 0){
				if(nxt==0 || pr[nxt-1]!=divv[cur]){
					pr[nxt++] = divv[cur];
				}
				cur = cur/divv[cur];
			}
			if(nxt==0 || pr[nxt-1]!=cur){
				pr[nxt++] = cur;
			}
			//for(int i=1;i<nxt;i++) assert(pr[i-1]>pr[i]);
			ll sum = 0;
			for(int mask=1;mask<(1<<nxt);mask++){
				int a = f[mask]; ll D = 1;
				for(int k=0;k<nxt;k++) if(((mask>>k)&1)) D = D*pr[k];
				if(a%2 == 1) sum += n/D;
				else sum -= n/D;
			}
			ll x = pr[nxt-1];
			ll y = max(x,n/x);
			int d = upper_bound(prr,prr+c,y)-prr;
			//[d,c)
			//cout<<prr[d]<<endl;
			ans[i] -= (c-d)*2; //cout<<i<<" "<<c<<" "<<d<<endl;
			ans[i] += sum-1; //cout<<i<<" "<<sum<<endl;
		}
	}
	ll comp = 0,ret = 0;
	for(int i=2;i<=n;i++){
		if(i*2 > n && divv[i] == 0) continue;
		comp++; ret += ans[i]; //cout<<ans[i]<<endl;
	}
	comp = comp*(comp-1)/2; //cout<<comp<<endl;
	ret /= 2;
	cout<<comp*2-ret<<endl;
}