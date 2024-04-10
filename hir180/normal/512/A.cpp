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
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int n;
	string s[105];
	cin >> n;
	for(int i=0;i<n;i++) cin >> s[i];
	vector<int>edge[26];
	bool ex[26][26]={};
	int in[26]={};
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=0;k<min(s[i].size(),s[j].size());k++)
			{
				if(s[i][k] != s[j][k])
				{
					int a = s[i][k]-'a';
					int b = s[j][k]-'a';
					if(ex[a][b]) goto nxt;
					ex[a][b] = true;
					edge[a].pb(b);
					in[b]++;
					goto nxt;
				}
			}
			if(s[i].size() > s[j].size())
			{
				puts("Impossible"); return 0;
			} nxt:;
		}
	}
	queue<int>que;
	string res = "";
	for(int i=0;i<26;i++) if(!in[i]) que.push(i);
	bool used[26]={};
	while(!que.empty())
	{
		res.pb(que.front() + 'a');
		int x = que.front(); used[x] = true;
		que.pop();
		for(int i=0;i<edge[x].size();i++)
		{
			in[edge[x][i]]--;
			if(in[edge[x][i]] == 0) que.push(edge[x][i]);
		}
	}
	for(int i=0;i<26;i++) if(in[i]) {puts("Impossible"); return 0;}
	for(int i=0;i<26;i++) if(!used[i]) res.pb(i+'a');
	cout << res << endl;
}