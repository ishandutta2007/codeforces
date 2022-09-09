#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXL = 3e5 + 5;

namespace AHO_CORASICK
{
	int son[MAXL][26], fail[MAXL], f[MAXL], pcnt = 0, hd = 0;
	inline int new_Node(void)
	{
		int res;
		if(hd) res = hd, hd = son[hd][0];
		else res = ++pcnt;
		memset(son[res], 0, sizeof(son[res]));
		fail[res] = 0; f[res] = 0;
		return res;
	}
	inline void del_Node(int u){ son[u][0] = hd; hd = u;}
	
	struct Aho_Corasick
	{
		int rt;
		vector<int> q;
		Aho_Corasick(void): rt(0) {}
		inline void insert(const string &s,int k)
		{
			if(!s.size()) return;
			if(rt == 0) rt = new_Node();
			int u = rt;
			for(int i=0; i<(int)s.size(); ++i)
			{
				int c = s[i] - 'a';
				if(!son[u][c]) son[u][c] = new_Node();
				u = son[u][c];
			}
			f[u] += k;
		}
		inline void build(void)
		{
			q.clear();
			if(rt == 0) return;
			q.push_back(rt);
			for(int it=0; it<(int)q.size(); ++it)
			{
				int u = q[it];
				if(u != rt) f[u] += f[fail[u]];
				for(int i=0; i<26; ++i)
				{
					int &v = son[u][i];
					if(v == 0) v = u == rt? rt: son[fail[u]][i];
					else fail[v] = u == rt? rt: son[fail[u]][i], q.push_back(v);
				}
			}
		}
		inline void clear(void){ for(int u: q) del_Node(u);}
		
		inline ll query(const string &s)
		{
			if(rt == 0) return 0;
			int u = rt;
			ll res = 0;
			for(int i=0; i<(int)s.size(); ++i)
			{
				u = son[u][s[i] - 'a'];
				res += f[u];
			}
			return res;
		}
	};
} using AHO_CORASICK::Aho_Corasick;

vector<Aho_Corasick> acam;
vector<int> mxid;

string s[MAXL];
int val[MAXL], m = 0;

int main(void)
{
	int Q;
	scanf("%d",&Q);
	acam.resize(1); mxid.resize(1);
	while(Q--)
	{
		int type;
		string cur;
		cin >> type >> cur;
		if(type == 1 || type == 2)
		{
			s[++m] = cur;
			val[m] = type == 1? 1: -1;
			while(mxid.size() > 1)
			{
				int t = (int)mxid.size() - 1;
				int len = mxid[t] - mxid[t-1];
				if(len != m - mxid[t]) break;
				
				acam.back().clear();
				acam.pop_back(); mxid.pop_back();
			}
			int lef = mxid.back() + 1;
			
			mxid.push_back(m);
			acam.push_back(Aho_Corasick());
			
			Aho_Corasick &t = acam[(int)acam.size() - 1];
			for(int i=lef; i<=m; ++i)
				t.insert(s[i], val[i]);
			t.build();
		}
		else
		{
			ll res = 0;
			for(int i=1; i<(int)acam.size(); ++i)
				res += acam[i].query(cur);
			printf("%lld\n",res);
			fflush(stdout);
		}
	}
	return 0;
}