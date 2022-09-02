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
int cnt[1000005][11];
int val[1000005];
int main(){
	for(int i=1;i<=1000000;i++){
		int x = i;
		while(x>=10){
			int v = 1,u = x;
			while(u){
				if(u%10 != 0) v *= (u%10);
				u /= 10;
			}
			x = v;
		}
		val[i] = x;
		for(int j=0;j<11;j++) cnt[i][j] = cnt[i-1][j];
		if(1<=val[i] && val[i]<=9){
			cnt[i][val[i]]++;
		}
	}
	int q; scanf("%d",&q);
	rep(t,q){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",cnt[b][c]-cnt[a-1][c]);
	}
}