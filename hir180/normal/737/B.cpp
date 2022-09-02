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
int n,a,b,k;
string s;
int main()
{
	cin >> n >> a >> b >> k >> s; s.pb('1'); n++;
	int u = -1,v = -1;
	vector<P>vec;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '0'){
			if(u == -1) {u = i; v = i;}
			else v = i;
		}
		else{
			if(v != -1){
				cnt += (v-u+1)/b;
				vec.pb(mp(u,v));
			}
			u  = -1; v = -1;
		}
	}
	assert(cnt >= a);
	vector<int>ans;
	for(int i=0;i<vec.size();i++){
		int B = vec[i].fi+b-1;
		while(B<=vec[i].sc && cnt>=a){
			ans.pb(B+1); B += b; cnt--;
		}
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
}