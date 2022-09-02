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
int edge[1005];
bool used[1005]={};
bool ok[1005]={};
bool cover[1005]={};
vector<int>com;
int n,x;
int main(){
	cin >> n >> x;
	fill(edge,edge+1005,-1);
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		if(a)
		{
			edge[a]=(i+1);
			cover[i+1]=true;
		}
	}
	int be=1;
	for(int i=1;i<=n;i++)
	{
		if(used[i] || edge[i]==-1 || cover[i]) continue;
		bool g=used[x];
		used[i]=true;
		int cur=i;
		int s=1;
		if(cur==x) be=s;
		while(edge[cur]!=-1) { cur=edge[cur]; s++; if(cur==x) be=s; used[cur]=true;}
		if(g!=used[x]) continue;
		com.pb(s);
	}

	for(int i=1;i<=n;i++)
	{
		if(!used[i] && edge[i]==-1) if(i!=x) com.pb(1);
	}

	ok[be]=true;
	//cout << be << endl << endl;
	for(int i=0;i<com.size();i++)
	{
		//cout << com[i] << endl;
		for(int j=n-com[i];j>=be;j--)
		{
			if(ok[j]) ok[j+com[i]]=true;
		}
	}
	//cout << endl;
	for(int i=1;i<=n;i++)
	{
		if(ok[i]) cout << i << endl;
	}
}