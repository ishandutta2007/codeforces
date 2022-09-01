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
string s;
int n;
vector<int>pos[26];
int main(){
	cin>>n>>s;
	int q; cin>>q;
	rep(i,n) pos[s[i]-'a'].push_back(i);
	while(q--){
		string ss; cin>>ss;
		int ans = -1;
		int cnt[26]={};
		rep(i,ss.size()) cnt[ss[i]-'a']++;
		rep(i,26) if(cnt[i])ans = max(ans,pos[i][cnt[i]-1]);
		cout << ans+1 << endl;
	}}