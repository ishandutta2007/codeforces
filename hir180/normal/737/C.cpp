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
int n,s,num[200005];
int cnt[200005];
int main()
{
	scanf("%d%d",&n,&s); for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	vector<int>vec; int ans = 0,use = 0;
	for(int i=1;i<=n;i++){
		if(i!=s && num[i] == 0) {use++; ans++;}
		else if(i!=s){
			vec.pb(num[i]);
			cnt[num[i]]++;
		}
		if(i==s && num[i] != 0) ans++;
	}
	SORT(vec);
	int lb = -1,ub = vec.size();
	while(ub-lb > 1){
		int mid = (ub+lb)/2;
		int f = vec[vec.size()-1-mid];
		int V = 0,pre = -1;
		for(int i=0;i<=vec.size()-1-mid;i++){
			if(pre != vec[i]) V++;
			pre = vec[i];
		}
		if(f-V <= use+mid) ub = mid;
		else lb = mid;
	}
	cout << ans+ub << endl;
}