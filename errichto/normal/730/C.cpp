#include <bits/stdc++.h>
using namespace std;

struct sklep
{
	long long cena;
	int mias;
	long long ile;
	sklep(){}
};

bool operator < (sklep a, sklep b)
{
	return a.cena<b.cena;
}

int n, m;

int p1, p2;
vector <int> graf[5007];

int w;
sklep tab[5007];

queue <int> bfs;
int odl[5007];

int q;
int start;
long long chce;
long long lim;

int check(int v)
{
	long long jesz=chce;
	long long aktu=0;
	long long pom=0;
	for (int i=1; i<=w; i++)
	{
		if (odl[tab[i].mias]<=v)
		{
			pom=min(jesz, tab[i].ile);
			jesz-=pom;
			aktu+=tab[i].cena*pom;
		}
		if (!jesz)
			break;
	}
	if (jesz || aktu>lim)
		return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	scanf("%d", &w);
	for (int i=1; i<=w; i++)
		scanf("%d%lld%lld", &tab[i].mias, &tab[i].ile, &tab[i].cena);
	sort(tab+1, tab+1+w);
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d%lld%lld", &start, &chce, &lim);
		for (int i=1; i<=n; i++)
			odl[i]=n*2;
		odl[start]=0;
		bfs.push(start);
		while(!bfs.empty())
		{
			int v=bfs.front();
			bfs.pop();
			for (int i=0; i<(int)graf[v].size(); i++)
			{
				if (odl[graf[v][i]]==n*2)
				{
					odl[graf[v][i]]=odl[v]+1;
					bfs.push(graf[v][i]);
				}
			}
		}
		if (!check(2*n-1))
		{
			printf("-1\n");
			continue;
		}
		int bsa=0;
		int bsb=n;
		int bss;
		while(bsa<bsb)
		{
			bss=(bsa+bsb)/2;
			if (check(bss))
				bsb=bss;
			else
				bsa=bss+1;
		}
		printf("%d\n", bsa);
	}
	return 0;
}