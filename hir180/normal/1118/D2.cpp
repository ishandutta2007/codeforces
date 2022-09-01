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
typedef pair<P,int> P1;
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
int n,m;
int a[200005];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int lb = 0,ub = n+1;
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		int cur = 0,cnt = 0;
		ll sum = 0;
		for(int i=n-1;i>=0;i--){
			sum += max(0,a[i]-cur);
			cnt++;
			if(cnt == mid){
				cnt = 0;
				cur++;
			}
		}
		if(sum >= m) ub = mid;
		else lb = mid;
	}
	if(ub == n+1) ub = -1;
	cout<<ub<<endl;
}