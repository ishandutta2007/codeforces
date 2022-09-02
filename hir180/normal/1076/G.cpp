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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,q;
ll a[200005];
int go[1905][32][2];
//
int lazy_lazy[1905];
#define sz 114
void remake(int i){
	int L = i*sz;
	int R = (i+1)*sz-1;
	R = min(R,n-1);
	if(lazy_lazy[i]){
		for(int x=L;x<=R;x++) a[x] ^= 1;
		lazy_lazy[i] = 0;
	}
	for(int j=0;j<(1<<m);j++){
		int cur = j;
		for(int x=R;x>=L;x--){
			if(cur == (1<<m)-1 && a[x]%2 == 1){
				cur /= 2;
			}
			else{
				cur /= 2;
				cur += (1<<m)/2;
			}
		}
		go[i][j][0] = cur;
		
		//reverse
		cur = j;
		for(int x=R;x>=L;x--){
			if(cur == (1<<m)-1 && a[x]%2 == 0){
				cur /= 2;
			}
			else{
				cur /= 2;
				cur += (1<<m)/2;
			}
		}
		go[i][j][1] = cur;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		a[i] %= 2;
	}
	for(int i=0;i<=(n-1)/sz;i++){
		remake(i);
	}
	rep(i,q){
		int ty; scanf("%d",&ty);
		if(ty == 1){
			int l,r; ll d; scanf("%d%d%lld",&l,&r,&d); l--; r--;
			if(d%2 == 0) continue;
			int L = l/sz;
			int R = r/sz;
			//L
			for(int w=l;w<=r;w++){
				if(w/sz > L) break;
				a[w] ^= 1;
			}
			if(L != R){
    			for(int w=r;w>=l;w--){
    				if(w/sz < R) break;
    				a[w] ^= 1;
    			}
			}
			remake(L);
			if(L != R) remake(R);
			for(int e=L+1;e<R;e++) lazy_lazy[e] ^= 1;
		}
		else{
			int l,r; scanf("%d%d",&l,&r);l--; r--;
			int L = l/sz;
			int R = r/sz;
			//L
			int cur = (1<<m)-1;
			for(int w=r;w>=l;w--){
				if(w/sz < R) break;
				if(cur == (1<<m)-1 && (a[w]^lazy_lazy[R]) == 1){
					cur /= 2;
				}
				else{
					cur /= 2;
					cur += (1<<m)/2;
				}
			}
			for(int e=R-1;e>=L+1;e--) cur = go[e][cur][lazy_lazy[e]];
			if(L != R){
				int las = (L+1)*sz-1;
				for(int w=las;w>=l;w--){
					if(cur == (1<<m)-1 && (a[w]^lazy_lazy[L]) == 1){
						cur /= 2;
					}
					else{
						cur /= 2;
						cur += (1<<m)/2;
					}
				}
			}
			int flag = (cur >= (1<<m)/2);
			printf("%d\n",2-flag);
		}
	}
}