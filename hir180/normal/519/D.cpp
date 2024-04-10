#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
 
using namespace std;
 
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef long long ll;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define INF 100000000
ll rui[100005];
ll get(int i,int j)
{
	if(i == 0) return rui[j];
	else return rui[j]-rui[i-1];
}
int main()
{
	ll v[26];
	for(int i=0;i<26;i++) cin >> v[i];
	string s; cin >> s;
	vector<int>pos[26];
	for(int i=0;i<s.size();i++)
	{
		if(i == 0) rui[0] = v[(s[i]-'a')];
		else rui[i] = rui[i-1]+v[(s[i]-'a')];
		pos[(s[i]-'a')].pb(i);
	}
	ll res = 0;
	for(int i=0;i<26;i++)
	{
		if(pos[i].size() <= 1) continue;
		vector<ll>val;
		map<ll,int>cnt;
		for(int j=1;j<pos[i].size();j++)
		{
			val.pb(get(pos[i][j-1]+1,pos[i][j]-1)+v[i]);
		}
		vector<ll>r;
		for(int j=0;j<val.size();j++)
		{
			if(j == 0) r.pb(val[0]);
			else r.pb(r[j-1]+val[j]);
		}
		for(int j=0;j<r.size();j++) if(r[j] == v[i]) res++;
		for(int j=0;j<r.size();j++)
		{
			res += cnt[r[j]-v[i]];
			cnt[r[j]]++;
		}
	}
	cout << res << endl;
}