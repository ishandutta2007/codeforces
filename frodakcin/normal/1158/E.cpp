#include <iostream>
#include <cstdio>

#include <bitset>
#include <vector>
#include <cstring>

#include <cassert>

using namespace std;

const int MN = 1<<10;
int N;
using vb = bitset<MN>;
using vi = vector<int>;
using vvb = vector<vb>;
#define pb push_back
vi ndep[MN];
vb bdep[MN];
vb tdep[MN];
int dep[MN];
int d[MN];
char x;

vi a[MN];
vb tmp[MN];

vb res;
vb all;
vb non;
int QC;
vb qry;
bool Q(void)
{
	for(int i = 0;i < N;i++) if(d[i] >= N) return res=all, 0;
	for(int i = 0;i <= N;i++)
		if(i == N) return res=non, 0;
		else if(d[i]) break;
	assert(++QC <= 80);
	printf("? "); for(int i = 0;i < N;i++) printf("%d%c", d[i], "\n "[i<N-1]);
	fflush(stdout);
	for(int i = 0;i < N;i++) scanf(" %c", &x), res[i] = x=='1';
	return 1;
}
bool Q2(void)
{
	memset(d, 0, sizeof d);
	for(int i = 0;i < N;i++) d[i] = qry[i];
	qry.reset();
	return Q();
}
void fil(int q, int v)
{
	for(int x : ndep[q])
		d[x] = v;
}
void move(int fro, int to)
{
	if(tmp[fro].count()==tdep[fro].count()) return;
	tdep[to] = tdep[fro]^tmp[fro];
	tdep[fro]=tmp[fro];
	for(int x = 0;x < N;x++)
		if(tdep[to][x]&&res[x])
			ndep[to].pb(x), bdep[to][x] = 1;
	//assert((bdep[fro]|tdep[fro])==tdep[fro]);
	//assert((bdep[to]|tdep[to])==tdep[to]);
}
vb chq[MN/3][MN];
int main(void)
{
	scanf("%d", &N);
	non.reset();
	for(int i = 0;i < N;i++) all[i] = 1;
	tdep[0] = all;
	bdep[0][0] = 1;
	ndep[0].pb(0);
	for(int i = 9;i >= 0;i--)
	{
		memset(d, 0, sizeof d);
		for(int j = 0;j < N;j+=1<<i+2)
			fil(j, (1<<i)-1);
		Q();
		memset(d, 0, sizeof d);
		for(int j = 0;j < N;j+=1<<i+2)
			tmp[j] = bdep[j]|res&tdep[j],fil(j, 1<<i);
		Q();
		for(int j = 0;j < N;j+=1<<i+2)
			move(j, j+(1<<i));

		memset(d, 0, sizeof d);
		for(int j = 1<<i+1;j < N;j+=1<<i+2)
			fil(j, (1<<i)-1);
		Q();
		memset(d, 0, sizeof d);
		for(int j = 1<<i+1;j < N;j+=1<<i+2)
			tmp[j] = bdep[j]|res&tdep[j],fil(j, 1<<i);
		Q();
		for(int j = 1<<i+1;j < N;j+=1<<i+2)
			move(j, j+(1<<i));
	}
	/*debug
	for(int i = 0;i < N;i++)
		for(int j : ndep[i])
			printf("d: %d, n: %d\n", i, j+1);
	*/
	for(int z = 0;z < 3;z++)
	{
		for(int i = 0;i*3+z+1 < N;i++)
			for(int j = 0;j < ndep[3*i+z].size();j++)
				chq[i][j] = !j?bdep[3*i+z+1]:non;
		for(int q = 9;q >= 0;q--)
		{
			bool c = 0;
			for(int i = z, v = 0;i+1 < N;i+=3, v++, c=0)
				for(int j = 0, k = 0;j < ndep[i].size();j++, k++)
				{
					if(k>>q) c=!c, k=0;
					qry[ndep[i][j]]=!c;
				}
			Q2();
			c = 0;
			for(int i = z, v = 0;i+1 < N;i+=3, v++)	
				for(int j = 0;j < ndep[i].size();j+=1<<q+1, c=!c)
					chq[v][j+(1<<q)] = chq[v][j]^(chq[v][j]&res), chq[v][j]&=res;
		}
		for(int i = 0;i*3+z+1 < N;i++)
			for(int j = 0, r, k;j < ndep[3*i+z].size();j++)
				for(k = 0, r = ndep[3*i+z][j];k < N;k++)
					if(chq[i][j][k])
						a[r].pb(k);
	}
	printf("!\n");
	for(int i = 0;i < N;i++)
		for(int x : a[i])
			printf("%d %d\n", i+1, x+1);
	fflush(stdout);
	return 0;
}