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
#define mod 924844033
int main()
{
	int n,num[105];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]); scanf("\n");
	for(int i=1;i<=n;i++){
		char str[1005];
		gets(str);
		int n = strlen(str);
		int cnt = 0;
		for(int j=0;j<n;j++){
			cnt += (str[j]=='a' || str[j]=='i' || str[j]=='u' || str[j]=='e' || str[j]=='o' || str[j]=='y');
		}
		if(cnt != num[i]){
			puts("NO"); return 0;
		}
	}
	puts("YES");
}