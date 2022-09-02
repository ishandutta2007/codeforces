#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 10000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
int n,k;
set<int>used;
deque<int>deq;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int a; scanf("%d",&a);
		if(used.find(a) != used.end()) continue;
		else{
			if(deq.size() < k) deq.push_front(a);
			else{
				deq.push_front(a);
				int b = deq[k];
				deq.pop_back();
				used.erase(b);
			}
			used.insert(a);
		}
	}
	cout << deq.size() << endl;
	rep(i,deq.size()) printf("%d\n",deq[i]);
}