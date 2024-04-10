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
int n;
ll xa,xb,c[300006];
ll mx[300005];
int who[300005];
P p[300005];
int mpg[300005];
int main(){
	scanf("%d%lld%lld",&n,&xa,&xb);
	rep(i,n){
	    scanf("%lld",&c[i]);
	    p[i] = mp(c[i],i);
	}
	sort(c,c+n);
	sort(p,p+n);
	for(int i=0;i<n;i++) mpg[i] = p[i].sc+1;
	who[n] = n;
	for(int i=n-1;i>=0;i--){
		if(mx[i+1] < c[i] * (n-i)){
			who[i] = i;
		}
		else{
			who[i] = who[i+1];
		}
		mx[i] = max(mx[i+1],c[i] * (n-i));
	}
	for(int i=0;i<n;i++){
		//xa
		ll need = (xa+c[i]-1)/c[i];
		if(i+need-1 < n){
			//i+need,....,n-1best
			if(mx[i+need] >= xb){
				puts("Yes");
				int w = who[i+need];
				//w->n-1
				printf("%lld %d\n",need,n-w);
				for(int ii=0;ii<need;ii++) printf("%d ",mpg[i+ii]);
				puts("");
				for(int ii=0;ii<n-w;ii++) printf("%d ",mpg[w+ii]);
				return 0;
			}
		}
		//xb
		need = (xb+c[i]-1)/c[i];
		if(i+need-1 < n){
			//i+need,....,n-1best
			if(mx[i+need] >= xa){
				puts("Yes");
				int w = who[i+need];
				//cout<<w<<endl;
				//w->n-1
				printf("%d %lld\n",n-w,need);
				for(int ii=0;ii<n-w;ii++) printf("%d ",mpg[w+ii]);
				puts("");
				for(int ii=0;ii<need;ii++) printf("%d ",mpg[i+ii]);
				return 0;
			}
		}
	}
	
	puts("No");
}