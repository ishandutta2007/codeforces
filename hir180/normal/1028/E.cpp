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
ll a[200005];
ll b[200005];
int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n){
		if(a[i] < a[(i+1)%n]){
			//ok
			b[(i+1)%n] = a[(i+1)%n];
			int cur = i;
			while(cur != (i+1)%n){
				//b[cur] = a[cur] + b[(cur+1)%n]
				b[cur] = a[cur] + b[(cur+1)%n];
				while(b[cur] <= 191919) b[cur] += b[(cur+1)%n];
				cur = (cur+n-1)%n;
			}
			puts("YES");
			for(int i=0;i<n;i++) printf("%lld ",b[i]);
			puts(""); return 0;
		}
	}
	//all a[i] is same
	if(a[0] == 0){
		puts("YES");
		rep(i,n) printf("1 ");
		puts("");
		return 0;
	}
	else{
		puts("NO");
	}
}