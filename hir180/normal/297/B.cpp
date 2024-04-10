#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
vector<int> N,M;
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	if(n>m){
		puts("YES");
		return 0;
	}
	for(int i=0;i<n;i++){
		int s;
		scanf("%d",&s);
		N.pb(s);
	}
	for(int i=0;i<m;i++){
		int s;
		scanf("%d",&s);
		M.pb(s);
	}
	sort(N.begin(),N.end());
	sort(M.begin(),M.end());
	bool ok=false;
	for(int i=0;i<n;i++){
		if(N[i]>M[i+m-n]){
			ok=true;
		}
	}
	puts(ok?"YES":"NO");
}