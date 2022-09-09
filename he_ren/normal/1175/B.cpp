#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
const int MAXN = 1e5 + 5;
const ll mxx = (1ll<<32) - 1;

int type[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		string s;
		cin>>s;
		if(s == "for") scanf("%d",&type[i]);
		else if(s == "end") type[i] = -1;
		else type[i] = 0;
	}
	
	stack<pil> sta;
	sta.push(make_pair(1,0));
	
	for(int i=1; i<=n; ++i)
	{
		if(type[i] == 0)
		{
			pil cur = sta.top(); sta.pop();
			
			++cur.second;
			if(cur.second > mxx / cur.first){ printf("OVERFLOW!!!"); return 0;}
			
			sta.push(cur);
			continue;
		}
		if(type[i] == -1)
		{
			pil cur = sta.top(); sta.pop();
			if(cur.second > mxx / cur.first){ printf("OVERFLOW!!!"); return 0;}
			
			ll res = cur.first * cur.second;
			
			cur = sta.top(); sta.pop();
			cur.second += res;
			if(cur.second > mxx / cur.first){ printf("OVERFLOW!!!"); return 0;}
			
			sta.push(cur);
			continue;
		}
		sta.push(make_pair(type[i], 0));
	}
	
	pil cur = sta.top();
	if(cur.second > mxx / cur.first){ printf("OVERFLOW!!!"); return 0;}
	printf("%lld",cur.first * cur.second);
	return 0;
}