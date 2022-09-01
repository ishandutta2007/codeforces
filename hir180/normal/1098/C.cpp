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
ll sum;
vector<int>num[100005];
int edge[100005];
void construct(vector<int>dep,int mn){
	SORT(dep);
	for(int i=0;i<dep.size();i++){
		num[dep[i]].pb(i+1);
	}
	for(int i=2;i<=100000;i++){
		if(num[i].size() == 0) continue;
		int sz = num[i-1].size();
		int sz2 = num[i].size();
		assert(1LL*sz*mn >= sz2);
		int cur = 0;
		int use = 0;
		for(int j=0;j<num[i].size();j++){
			edge[num[i][j]] = (num[i-1][cur]);
			use++;
			if(use == mn){
				use = 0;
				cur++;
			}
		}
	}
	puts("Yes");
	for(int i=2;i<=n;i++) printf("%d ",edge[i]);
	puts("");
}
int main(){
	cin>>n>>sum;
	ll mx = 1LL*n*(n+1)/2;
	if(sum > mx){
		puts("No");
		return 0;
	}
	else if(sum == mx){
	    puts("Yes");
	    for(int i=2;i<=n;i++) printf("%d ",i-1);
	    puts(""); return 0;
	}
	for(int k=1;k<=n-1;k++){
		ll mn = 0;
		ll beg = 1;
		int cur = 1;
		int cnt = 0;
		while(cnt != n){
			if(cnt+beg <= n){
				cnt += beg;
				mn += 1LL*cur*beg;
			}
			else{
				mn += 1LL*cur*(n-cnt);
				cnt = n;
			}
			cur++;
			beg = min(beg*1LL*k,1LL*n);
		}
		if(mn > sum) continue;
		//ans is k
		vector<int>dep;
		dep.pb(1);
		int precnt = 0, curcnt = 1;
		ll S = 1;
		for(int i=1;i<n;i++){
			int ch = dep[i-1];
			int t = ch;
			if(1LL*precnt*k > 1LL*curcnt){
				dep.pb(t);
				ll mxS = S+t;
				//t+1.....t+1+n-2-i
				mxS += 1LL*(t+1+t+1+n-2-i)*(n-1-i)/2;
				ll mnS = S+t;
				int zan = n-1-i;
				ll cur_num;
			    for(int e=t;zan;e++){
					if(e == t){
						ll use = 1LL*precnt*k-1LL*curcnt-1;
						use = min(use,1LL*n);
						if(zan > use){
							mnS += use * 1LL * e;
							zan -= use;
							cur_num = 1LL*curcnt+1+use;
							cur_num = min(cur_num,1LL*n);
						}
						else{
							mnS += zan * 1LL * e;
							break;
						}
					}
					else{
						ll use = cur_num*k;
						use = min(use,1LL*n);
						if(zan > use){
							mnS += use * 1LL * e;
							cur_num = use;
							zan -= use;
						}
						else{
							mnS += zan * 1LL * e;
							break;
						}
					}
				}
				if(mnS <= sum && sum <= mxS){
					curcnt++;
					S += t;
					continue;
				}
				else{
					dep.pop_back();
				}
			}
			dep.pb(t+1);
			precnt = curcnt; curcnt = 1;
			ll mxS = S+t+1;
			//t+2.....t+2+n-2-i
			mxS += 1LL*(t+2+t+2+n-2-i)*(n-1-i)/2;
			ll mnS = S;
			int zan = n-i;
			ll cur_num = precnt;
			for(int e=t+1;zan;e++){
				{
					ll use = cur_num*k;
					use = min(use,1LL*n);
					if(zan > use){
						mnS += use * 1LL * e;
						cur_num = use;
						zan -= use;
					}
					else{
						mnS += zan * 1LL * e;
						break;
					}
				}
			}
			assert(mnS <= sum && sum <= mxS);
			S += t+1;
		}
		ll SS = 0;
		rep(i,n) SS += dep[i];
		assert(SS == sum);
	    construct(dep,k);
	    return 0;
	}
	puts("No");
	return 0;
}