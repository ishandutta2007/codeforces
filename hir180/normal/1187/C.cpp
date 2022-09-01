#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <assert.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fi first
#define sc second
typedef pair<int,int> P;
typedef pair<P,P> P2;
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
int n,m;
bool ok[1005];
vector<P>query;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int t,a,b; cin>>t>>a>>b;
		if(t == 1){
			for(int j=a;j<b;j++) ok[j] = 1;
		}
		else{
			query.pb(P(a,b));
		}
	}
	rep(i,query.size()){
		bool O = 0;
		for(int j=query[i].fi;j<query[i].sc;j++) if(!ok[j]) O = 1;
		if(!O){puts("NO");return 0;}
	}
	puts("YES");
	int cur = 500000;
	printf("%d",cur);
	for(int i=1;i<n;i++){
		if(!ok[i]) cur --;
		printf(" %d",cur);
	}
	puts("");}