#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

const int MN = 1e5 + 100;

template<int MS> struct dsu
{
	int p[MS], r[MS];
	void init(int S)
	{
		for(int i = 0;i <= S;i++) p[i] = -1, r[i] = 0;
	}
	int f(int n) {return ~p[n] ? p[n] = f(p[n]) : n;}
	bool m(int a, int b)
	{
		a = f(a), b = f(b);
		if(a==b) return 0;
		if(r[a]<r[b]) swap(a,b);
		r[a]+=r[a]==r[b], r[b] = -1, p[b] = a;
		return 1;
	}
};
dsu<MN> d;

int N;
bool same[MN];
char t[MN];

vector<int> Q;
bool res[MN];
void qry(void)
{
	if(Q.empty()) return;
	printf("Q %lu", Q.size()>>1);
	for(int x : Q) printf(" %d", x);
	printf("\n");
	fflush(stdout);
	scanf(" %s", t);
	if(t[0]=='-') exit(0);
	for(int i = 0;i < Q.size()>>1;i++)
		res[i]=t[i]=='1';
	Q.clear();
}

vector<int> g;
void form_groups(void)
{
	for(int i = 1;i < N;i+=2)
		Q.push_back(i), Q.push_back(i+1);
	qry();
	for(int i = 1, j = 0;i < N;i+=2, j++)
		same[i]=res[j];
	
	for(int i = 2;i < N;i+=2)
		Q.push_back(i), Q.push_back(i+1);
	qry();
	for(int i = 2, j = 0;i < N;i+=2, j++)
		same[i]=res[j];

	g.clear();
	g.push_back(1);
	for(int i = 1;i < N;i++)
		if(same[i])
			d.m(i, i+1);
		else
			g.push_back(i+1);
}
bool sm2[MN];
void finalize(void)
{
	if(g.size() == 3)
	{
		Q.push_back(g[0]), Q.push_back(g[2]);
		qry();
		if(res[0]) d.m(g[0], g[2]);
	}
	for(int i = 0;i < g.size();i++) sm2[i] = 0;
	for(int k = 0;k < 4;k++)
	{
		for(int i = 3+k;i < g.size();i+=4)
		{
			Q.push_back(g[i-3]), Q.push_back(g[i-1]);
			Q.push_back(g[i-2]), Q.push_back(g[i]);
		}
		qry();
		for(int i = 3+k, j=0;i < g.size();i+=4, j+=2)
		{
			if(res[j]) d.m(g[i-3], g[i-1]), sm2[i-3] = 1;
			if(res[j+1]) d.m(g[i-2], g[i]), sm2[i-2] = 1;
			if(!res[j]&&!res[j+1]) d.m(g[i-3], g[i]);
		}
	}
	for(int i = 0, j;i+3 < g.size();)
	{
		if(sm2[i]) {i++;continue;}
		for(j = i+1;j+2 < g.size()&&sm2[j];j++);
		if(j+2 >= g.size()) break;
		d.m(g[i], g[j+2]);
		i = j;
	}
}
vector<int> fin;
vector<int> r[MN];
void answer(void)
{
	fin.clear();
	for(int i = 1;i <= N;i++)
	{
		r[d.f(i)].push_back(i);
		if(!~d.p[i])
			fin.push_back(i);
	}
	while(fin.size() < 3) fin.push_back(N+1);
	printf("A");
	for(int x : fin) printf(" %lu", r[x].size());
	printf("\n");
	for(int x : fin)
	{
		for(int i = 0;i < r[x].size();i++)
			printf("%d%c", r[x][i], " \n"[i==r[x].size()-1]);
		if(r[x].empty()) printf("\n");
		r[x].clear();
	}
	fflush(stdout);
}
void solve(void)
{
	scanf("%d", &N);
	if(!~N) exit(0);
	d.init(N);
	form_groups();//cerr << "formed_groups\n";
	finalize();//cerr << "finalized\n";
	answer();//cerr << "answered\n";
}
int main(void)
{
	int T;
	scanf("%d", &T);
	for(int i = 0;i < T;i++)
		solve();
	return 0;
}