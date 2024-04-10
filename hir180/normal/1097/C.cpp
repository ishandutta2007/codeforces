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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
char ch[500005];
int cnt[500005][2];
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%s",&ch);
		int s = strlen(ch);
		int mn = 0, sum = 0;
		rep(j,s){
			sum += (ch[j]=='('?1:-1);
			mn = min(mn,sum);
		}
		if(mn == 0){
			cnt[sum][0]++;
		}
		else{
			if(mn == sum) cnt[-sum][1]++;
		}
	}
	int ans = cnt[0][0]/2;
	for(int i=1;i<500005;i++) ans += min(cnt[i][0],cnt[i][1]);
	cout<<ans<<endl;
}