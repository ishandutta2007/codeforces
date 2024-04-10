#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
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
int cnt[5005],num[1000005],n,kk,CC[1000005];
int main(){
	scanf("%d%d",&n,&kk);
	for(int i=1;i<=n;i++) scanf("%d",&cnt[i]);
	sort(cnt+1,cnt+n+1); 
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
		num[cnt[j]-cnt[i]]++;
	}
	for(int i=1;i<=1000001;i++){
		int sz = 0,C = 0,j;
		for(j=i;j<=1000001;j+=i){
			sz += num[j];
	    	if(sz > kk*(kk+1)/2) goto bad;
		}
		for(j=1;j<=n;j++){
			CC[cnt[j]%i]++;
			if(CC[cnt[j]%i]>=2) C++;
		}
		for(j=1;j<=n;j++){
			CC[cnt[j]%i]--;
		}
		if(C>kk) goto bad;
		cout<<i<<endl; return 0;
		bad:;
	}
}