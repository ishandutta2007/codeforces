#include <bits/stdc++.h>
using namespace std;

struct node
{
	int id;
	int roz;
	int pri;
	node * lew;
	node * pra;
	node * oj;
	node()
	{
		lew=NULL;
		pra=NULL;
		oj=NULL;
		roz=1;
		pri=rand();
	}
	node(int idid)
	{
		id=idid;
		lew=NULL;
		pra=NULL;
		oj=NULL;
		roz=1;
		pri=rand();
	}
	void update()
	{
		roz=1;
		if (lew!=NULL)
			roz+=lew->roz;
		if (pra!=NULL)
			roz+=pra->roz;
	}
};

node * merge(node * v, node * u)
{
	if (v==NULL)
		return u;
	if (u==NULL)
		return v;
	if ((v->pri)>=(u->pri))
	{
		v->pra=merge(v->pra, u);
		if (v->pra!=NULL)
			v->pra->oj=v;
		v->update();
		return v;
	}
	else
	{
		u->lew=merge(v, u->lew);
		if (u->lew!=NULL)
			u->lew->oj=u;
		u->update();
		return u;
	}
}

pair <node*, node*> split(node * v, int chceroz)
{
	if (v==NULL)
		return make_pair(v, v);
	v->oj=NULL;
	int nalew=1;
	if (v->lew!=NULL)
		nalew+=v->lew->roz;
	if (nalew<=chceroz)
	{
		pair <node*, node*> ret=split(v->pra, chceroz-nalew);
		v->pra=ret.first;
		if (v->pra!=NULL)
			v->pra->oj=v;
		v->update();
		ret.first=v;
		return ret;
	}
	else
	{
		pair <node*, node*> ret=split(v->lew, chceroz);
		v->lew=ret.second;
		if (v->lew!=NULL)
			v->lew->oj=v;
		v->update();
		ret.second=v;
		return ret;
	}
}

int poznaj(node * v, int czytu)
{
	//printf("poznaje w %d\n", v->id);
	int ret=1;
	if (v->lew!=NULL)
		ret+=v->lew->roz;
	if (!czytu)
		ret=0;
	if (v->oj==NULL)
		return ret;
	return ret+poznaj(v->oj, ((v->oj->pra)==v));
}

node * korz;

int t;

int n, m;

int ss, tt;

vector <int> graf[1000007];

int bylo[1000007];

int ojc[1000007];

int odl[1000007];

int juz[1000007];

vector < pair < int , pair <int,int> > > kan;

vector <int> pro;

int ostkol[1000007];

node * wsk[1000007];

void czys()
{
	for (int i=1; i<=n; i++)
		bylo[i]=0;
}

void dfs1(int v, int oj)
{
	bylo[v]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			swap(graf[v][i], graf[v][0]);
	}
	for (int i=0; i<graf[v].size(); i++)
		if (!bylo[graf[v][i]])
			dfs1(graf[v][i], v);
}

void dfs2(int v)
{
	bylo[v]=1;
	//printf("%d ojcem %d\n", ojc[v], v);
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==ojc[v])
			continue;
		if (!bylo[graf[v][i]])
		{
			odl[graf[v][i]]=odl[v]+1;
			ojc[graf[v][i]]=v;
			dfs2(graf[v][i]);
			continue;
		}
		if (odl[v]>odl[graf[v][i]])
			kan.push_back(make_pair(odl[graf[v][i]], make_pair(v, graf[v][i])));
	}
}

int stin[1000007];
int stout[1000007];
vector <int> ngraf[1000007];

int main()
{
	srand(69);
	/*node * tab[50];
	tab[0]=new node(2);
	tab[1]=new node(5);
	tab[2]=new node(3);
	tab[3]=new node(4);
	tab[4]=merge(tab[0], tab[1]);
	tab[5]=merge(tab[2], tab[3]);
	tab[6]=merge(tab[5], tab[4]);
	tab[7]=split(tab[6], 3).first;
	printf("%d\n", poznaj(tab[0], 1));
	printf("%d\n", poznaj(tab[1], 1));
	printf("%d\n", poznaj(tab[2], 1));
	printf("%d\n", poznaj(tab[3], 1));
	printf("\n");
	printf("%d\n", tab[0]->roz);
	printf("%d\n", tab[1]->roz);
	printf("%d\n", tab[2]->roz);
	printf("%d\n", tab[3]->roz);
	printf("\n");
	return 0;*/
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d", &n, &m, &ss, &tt);
		for (int i=1; i<=n; i++)
			graf[i].clear();
		for (int i=1; i<=n; i++)
			wsk[i]=NULL;
		for (int i=1; i<=n; i++)
			juz[i]=0;
		for (int i=1; i<=m; i++)
		{
			int p1, p2;
			scanf("%d%d", &p1, &p2);
			graf[p1].push_back(p2);
			graf[p2].push_back(p1);
		}
		czys();
		dfs1(tt, 0);
		czys();
		odl[ss]=1;
		kan.clear();
		ojc[ss]=0;
		dfs2(ss);
		sort(kan.begin(), kan.end());
		//for (int i=0; i<kan.size(); i++)
		//	printf("%d  %d %d\n", kan[i].first, kan[i].second.first, kan[i].second.second);
		//printf("\n");
		pro.clear();
		int pom=tt;
		korz=NULL;
		while(pom)
		{
			//printf("WRZUCAM %d bo %d %d\n", pom, ss, tt);
			wsk[pom]=new node(pom);
			korz=merge(wsk[pom], korz);
			juz[pom]=1;
			pom=ojc[pom];
		}
		for (int i=0; i<kan.size(); i++)
		{
			int x=kan[i].second.first;
			int y=kan[i].second.second;
			if (juz[x])
				continue;
			vector <int> stos;
			int pom=x;
			int zjeb=0;
			while(!juz[pom])
			{
				if (pom==y)
				{
					zjeb=1;
					break;
				}
				stos.push_back(pom);
				pom=ojc[pom];
			}
			if (pom==y)
				continue;
			if (zjeb)
				continue;
			int raz=poznaj(wsk[y], 1);
			int dwa=poznaj(wsk[pom], 1);
			//printf("%d i %d\n", raz, dwa);
			if (raz>dwa)
			{
				swap(raz, dwa);
				swap(y, pom);
				reverse(stos.begin(), stos.end());
			}
			node * nowy = NULL;
			for (int j=0; j<stos.size(); j++)
			{
				wsk[stos[j]]=new node(stos[j]);
				nowy=merge(nowy, wsk[stos[j]]);
				juz[stos[j]]=1;
				//printf("%d\n", stos[j]);
				//pro.push_back(stos[j]);
			}
			pair <node *, node *> bier=split(korz, raz);
			korz=merge(merge(bier.first, nowy), bier.second);
			//printf("no okok\n");
		}
		//printf("MAM %d\n", korz->roz);
		if (korz->roz!=n)
		{
			printf("No\n");
			continue;
		}
		for (int i=1; i<=n; i++)
			ostkol[i]=poznaj(wsk[i], 1);
		for (int i=1; i<=n; i++)
		{
			stin[i]=0;
			stout[i]=0;
			ngraf[i].clear();
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=0; j<graf[i].size(); j++)
			{
				if (ostkol[i]<=ostkol[graf[i][j]])
				{
					ngraf[i].push_back(graf[i][j]);
					stout[i]++;
					stin[graf[i][j]]++;
				}
			}
		}
		int zjeb=0;
		for (int i=1; i<=n; i++)
		{
			if ((stout[i]==0)!=(i==tt))
				zjeb=1;
			if ((stin[i]==0)!=(i==ss))
				zjeb=1;
		}
		if (zjeb)
		{
			assert(0);
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		for (int i=1; i<=n; i++)
		{
			for (int j=0; j<graf[i].size(); j++)
			{
				if (ostkol[i]<=ostkol[graf[i][j]])
				{
					printf("%d %d\n", i, graf[i][j]);
				}
			}
		}
	}
	return 0;
}