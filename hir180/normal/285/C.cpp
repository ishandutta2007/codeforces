//CF#175Div2 by HIR180
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
long long num[300005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	sort(num,num+n);
	long long ans=0;
	for(long long int i=0;i<n;i++){
		ans+=abs((i+1)-num[i]);
	}
	printf("%lld\n",ans);
}