#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[50005];
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int lb = 0,ub = INF; //(lb,ub]
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		set<int>S;
		for(int i=1;i<=n;i++) if(a[i]<=mid) S.insert(a[i]);
		for(int i=n;i>=1;i--){
			if(a[i]<=mid) break;
			int x = a[i]; x/=2;
			while(x){
				if(x<=mid && S.find(x) == S.end()){
					S.insert(x); goto ok;
				}x/=2;
			}
			lb = mid; goto out; ok:;
		}
		ub = mid;out:;
	}
	set<int>S;
	for(int i=1;i<=n;i++){
		if(a[i]<=ub){
			S.insert(a[i]);
			printf("%d ",a[i]);
		}
	}
	for(int i=n;i>=1;i--){
		if(a[i]<=ub) break;
		int x = a[i]; x/=2;
		while(x){
			if(x<=ub && S.find(x) == S.end()){
				S.insert(x); printf("%d ",x); break;
			}x/=2;
		}
	}puts("");
}