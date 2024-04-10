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
int num[105][105];
vector<int>vec;
int n,m,d;
int main(){
	scanf("%d %d %d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&num[i][j]);
			vec.pb(num[i][j]);
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=1;i<vec.size();i++){
		if((vec[i]-vec[i-1])%d!=0){
			puts("-1");
			return 0;
		}
	}
	long long cur=0;
	for(int i=0;i<vec.size();i++){
		cur+=(long long)(vec[i]-vec[0])/d;
	}
	long long res=cur;
	for(int i=1;i<vec.size();i++){
		cur+=(long long)i*(long long)(vec[i]-vec[i-1])/d;
		cur-=(long long)(vec.size()-i)*(long long)(vec[i]-vec[i-1])/d;
		res=min(res,cur);
	}
	printf("%lld\n",res);
}