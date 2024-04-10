#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n;
int x[maxn], y[maxn];
int nx[maxn];
void otp() {
//	for (int i = 1; i <= n; i++) cout << x[i] << ' ' << y[i] << endl;
//	while (1);
	for (int i = 1; i <= n; i++) {
//		cout << x[i] << ' ' << y[i] << endl;
		vi cur;
		for (int j = 1; j <= n; j++)
			if (x[j] == 0 && y[j] == i) cur.pb(j);
	//	cout << cur.size() << endl;
		for (int k = 0; k < cur.size(); k += i)
			for (int s = 0; s < i; s++) {
				int u = cur[k + s], v = cur[k + (s + 1) % i];
				nx[u] = v;
			}
	}
	for (int i = 1; i <= n; i++)
		if (x[i] != 0)
			for (int j = 1; j <= n; j++)
				if (y[j] == y[i] && x[j] == x[i] - 1)
					nx[i] = j;
	for (int i = 1; i <= n; i++)
		cout << nx[i] << ' ';
}
struct edge
{
	int u, v, c;
	edge *rev;
	edge *next;
}pool[1000005], *h[maxn];
int cnt = 0;
void addedge(int u, int v, int c)
{
//	cout<<"ADE"<<u<<" "<<v<<" "<<c<<endl;
	edge *new1 = &pool[cnt++];
	new1->u = u, new1->v = v, new1->c = c;
	
	edge *new2 = &pool[cnt++];
	new2->u = v, new2->v = u, new2->c = 0;
	
	new1->rev = new2, new2->rev = new1;
	new1->next = h[u], h[u] = new1;
	new2->next = h[v], h[v] = new2;
}
int level[maxn], q[maxn], fr, ed;
int s, t;
void bfs()
{
	fr = ed = 0;
	memset(level, -1, sizeof(level));
	level[s] = 1, q[ed++] = s;

	while(fr < ed)
	{
		for(edge *p = h[q[fr]]; p; p = p->next)
		{
			if(!p->c || level[p->v] != -1) continue;
			level[p->v] = level[q[fr]] + 1, q[ed++] = p->v;
		}
		fr++;
	}
}
int dfs(int a, int flow)
{
//	cout << a << ' ' << s << ' ' << t << endl;
	if(!flow) return 0;
	if(a == t) return flow;
	int nf = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if((level[p->v] != level[a] + 1) || (p->c <= 0)) continue;
		int nflow = dfs(p->v, min(flow - nf, p->c));
		nf += nflow, p->c -= nflow, p->rev->c += nflow;
	}
	if(!nf) level[a] = -1;
	return nf;
}
int dinic()
{
	int ans = 0;
	while(1)
	{
		bfs();
		int nans = dfs(s, 1e9);
		if(!nans) break;
		ans += nans;
	}
	return ans;
}
int read() {
	char inp[6];
	scanf("%s", inp);
	if (inp[0] == '?') return -1;
	int l = strlen(inp), c = 0;
	for (int i = 0; i < l; i++)
		c = c * 10 + inp[i] - '0';
	return c;
} 
bool fl[maxn];
int u[maxn], v[maxn];
int idcnt;
bool push(int a, int b) {
	idcnt++;
	u[idcnt] = a, v[idcnt] = b;
	addedge(idcnt, t, 1);
	if (idcnt > n) return 0;
	return 1;
}
bool f[maxn][maxn];
int tr[maxn], ex[maxn], ey[maxn];
int main() {
	n = read();
	for (int i = 1; i <= n; i++) 
		x[i] = read(), y[i] = read();
	for (int mpl = 1; mpl <= n; mpl++) {
		memset(fl, 0, sizeof(fl));
		memset(f, 0, sizeof(f));
		fl[mpl] = 1;
		cnt = 0;
		for (int i = 0; i < maxn; i++) h[i] = NULL;
		idcnt = 0, 
		s = 2 * n + 1, t = 2 * n + 2;
		for (int i = 1; i <= n; i++)
			if (y[i] != -1) fl[y[i]] = 1;
		int tot = 0;
		for (int i = 1; i <= n; i++)
			tot += fl[i];
		if (!tot) fl[1] = 1;
		for (int i = 1; i <= n; i++) //  
		{
			if (!fl[i]) continue;
			int cnt = 0;
			for (int j = 1; j <= n; j++)
				if (x[j] == 0 && y[j] == i) 
					cnt++;
			int cur = i - cnt % i;
			if (cnt % i == 0 && cnt > 0) cur = 0;
			for (int j = 0; j < cur; j++) 
				if (!push(0, i)) break;
		}
		for (int i = 1; i <= n; i++)
			if (x[i] >= 0 && y[i] >= 0)
				for (int j = 1; j < x[i]; j++)
					f[j][y[i]] = 1; 
		int us = 0;
		for (int i = 1; i <= n; i++)
			us = max(us, x[i]);
		for (int j = us; j > 0; j--) 
			f[j][mpl] = 1; 
		for (int i = 1; i <= n; i++)
			if (x[i] >= 0 && y[i] >= 0)
				f[x[i]][y[i]] = 0;
		for (int i = 1; i <= n; i++) {
			if (idcnt > n) break;
			for (int j = 1; j <= n; j++)
				if (f[i][j]) 
					if (!push(i, j)) break;
		}
	//	cout << mpl << endl;
		if (idcnt > n) continue;
		int dcnt = idcnt;
		for (int i = 1; i <= n; i++) {
			if (x[i] != -1 && y[i] != -1) continue;
			dcnt++;
			tr[dcnt] = i;
			addedge(s, dcnt, 1);
			for (int j = 1; j <= idcnt; j++) {
				if (u[j] != x[i] && x[i] != -1) continue;
				if (v[j] != y[i] && y[i] != -1) continue;
				addedge(dcnt, j, 1);
			}
		} 
	//	cout << idcnt << ' ' << dcnt << endl;
	//	for (int i = 1; i <= dcnt; i++) cout << u[i] << ' ' << v[i] << endl;
	//	cout << idcnt << ' ' << dcnt << ' ' << u[1] << ' ' << v[1] << endl;
		if (dinic() < idcnt) continue;
		else {
			for (int i = idcnt + 1; i <= dcnt; i++)
				for (edge *p = h[i]; p; p = p->next)
					if (p->v == s) continue;
					else if (p->c == 0) x[tr[i]] = u[p->v], y[tr[i]] = v[p->v];
			for (int i = 1; i <= n; i++)
				if (x[i] == -1 && y[i] == -1) 
					x[i] = 1, y[i] = mpl;
				else if (x[i] == -1)
					x[i] = 1;
				else if (y[i] == -1) {
					if (x[i] == 0) y[i] = 1;
					else y[i] = mpl;
				}
		//	cout << "!!!" << mpl << endl;
		//	for (int i = 1; i <= n; i++) cout << x[i] << ' ' << y[i] << endl;
			otp();
			return 0;
		}
		l1:;
	}
	cout << -1 << endl;
	return 0;
}
/*
3
? ? 
? ?  
? ? 
*/