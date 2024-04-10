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
int n,k; bool u[55];
string ans[55];
int main(){
	cin>>n>>k;
	rep(i,n-k+1){
		string s;cin>>s;
		if(s[0]=='Y') u[i] = 1;
	}
	int c = 0;
	rep(i,n){
		if(ans[i].size()) continue;
		char A = 'A'+(c%26);
		char B = 'a'+(c/26);
		c++;
		ans[i].pb(A);
		ans[i].pb(B);
		string cp = ans[i];
		for(int j=i;j<n-k+1;j+=k-1){
			if(u[j] == 0){
				ans[j+k-1] = cp;
			}
			else{
				break;
			}
		}
	}
	rep(i,n) cout << ans[i] << " ";
	cout << endl;
}