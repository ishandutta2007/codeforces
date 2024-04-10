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
int q;
int main(){
	cin>>q;
	while(q--){
		ll a,b,c; cin>>a>>b>>c;
		ll x = a-min(b,c)+1;
		cout<<x<<endl;
	}
}