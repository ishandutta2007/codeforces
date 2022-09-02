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
int val[4096][4096],n,a[15],m,q;
int cnt[4096][1280];
int CC[4096];
int main(){
	cin>>n>>m>>q;
	rep(i,n) scanf("%d",&a[i]);
	char ch[16];
	rep(i,m){
		scanf("%s",ch);
		int C = 0;
		rep(i,n){
			C += (1<<i) * (ch[i]-'0');
		}
		CC[C]++;
	}
	for(int mask=0;mask<(1<<n);mask++){
		rep(mask2,(1<<n)){
			rep(x,n){
				if( ((mask>>x)&1) == ((mask2>>x)&1) ){
					val[mask][mask2] += a[x];
				}
			}
			cnt[mask][val[mask][mask2]]+=CC[mask2];
		}
		for(int i=1;i<1280;i++) cnt[mask][i] += cnt[mask][i-1];
	}
	rep(i,q){
		scanf("%s",ch);
		int C = 0;
		rep(i,n){
			C += (1<<i) * (ch[i]-'0');
		}
		int d; scanf("%d",&d);
		printf("%d\n",cnt[C][d]);
	}
}