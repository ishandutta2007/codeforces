#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;
const int eu[7] = {0, 1,0,1,0,0,1};
const int ed[7] = {0, 1,0,0,1,1,0};
const int el[7] = {0, 1,0,0,0,1,1};
const int er[7] = {0, 1,0,1,1,0,0};

/*
1 		2 		3 		4 		5 		6 
##		..		\#		./		\.		#/
##		..		.\		/#		#\		/.
*/

const char uhalf[7][4] = {"", "##", "..", "\\#", "./", "\\.", "#/"};
const char dhalf[7][4] = {"", "##", "..", ".\\", "/#", "#\\", "/."};

struct Paint_Board
{
	int n,m;
	vector< vector<int> > a, u, d, l, r;
	Paint_Board(int n,int m):
		n(n), m(m),
		a(n+2, vector<int>(m+2)),
		u(a), d(a), l(a), r(a) {}
	
	void set_clr(int x,int y,int clr)
	{
		a[x][y] = clr;
		u[x][y] = eu[clr];
		d[x][y] = ed[clr];
		l[x][y] = el[clr];
		r[x][y] = er[clr];
	}
	
	void set_line(int x,int clr)
	{
		for(int j=1; j<=m; ++j)
			set_clr(x,j, clr);
	}
	void set_line(int x,int clr1,int clr2)
	{
		for(int j=1; j<=m; ++j)
			set_clr(x,j, (j&1)? clr1: clr2);
	}
	
	void set_rd(int x,int y)
	{
		if(l[x][y+1])
		{
			if(u[x+1][y]) set_clr(x,y, 4);
			else set_clr(x,y, 3);
		}
		else
		{
			if(u[x+1][y]) set_clr(x,y, 5);
			else set_clr(x,y, 6);
		}
	}
	
	void set_lu(int x,int y)
	{
		if(r[x][y-1])
		{
			if(d[x-1][y]) set_clr(x,y, 6);
			else set_clr(x,y, 5);
		}
		else
		{
			if(d[x-1][y]) set_clr(x,y, 3);
			else set_clr(x,y, 4);
		}
	}
	
	void print(void)
	{
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=m; ++j)
				printf("%s",uhalf[a[i][j]]);
			putchar('\n');
			
			for(int j=1; j<=m; ++j)
				printf("%s",dhalf[a[i][j]]);
			putchar('\n');
		}
	}
};

int main(void)
{
	int n,m,b,w,c;
	scanf("%d%d%d%d%d",&n,&m,&b,&w,&c);
	
	Paint_Board board(n,m);
	
	board.set_line(0, 1);
	
	int bl = (b + m-1) / m;
	for(int i=1; i<=bl; ++i)
		board.set_line(i, 1);
	
	if(b%m)
	{
		for(int i=b%m+1; i<=m; ++i)
			board.set_lu(bl, i);
		
		board.set_clr(bl+1,0, ((b%m)&1)? 1: 2);
		for(int i=1; i<=b%m; ++i)
			board.set_lu(bl+1, i);
	}
	else board.set_line(bl+1, 3,6);
	
	for(int i = b%m? bl+1: bl+2; i<=n; ++i)
		for(int j = (i==bl+1? b%m+1: 1); j<=m; ++j)
		{
			if(w) board.set_clr(i,j, 2), --w;
			else board.set_lu(i,j);
		}
	
	board.print();
	return 0;
}