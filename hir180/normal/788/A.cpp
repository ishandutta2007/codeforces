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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int b[100005],n,a[100005];
ll rui[100005][2];
ll mx[100005][2];
int main(){
	cin>>n;
	repn(i,n)cin>>b[i];
	repn(i,n-1)a[i]=abs(b[i+1]-b[i]);
	n--;
	repn(i,n){
		if(i%2 == 1) rui[i][0] = rui[i-1][0]+a[i];
		else rui[i][0] = rui[i-1][0]-a[i];
		rui[i][1] = -rui[i][0];
	}
	for(int i=n;i>=1;i--){
		if(i==n){
			mx[i][0] = rui[i][0];
			mx[i][1] = rui[i][1];
		}
		else{
			mx[i][0] = max(mx[i+1][0],rui[i][0]);
			mx[i][1] = max(mx[i+1][1],rui[i][1]);
		}
	}
	ll ret = 0;
	repn(i,n){
		ret = max(ret,mx[i][1-i%2]-rui[i-1][1-i%2]);
	}
	cout<<ret<<endl;
}