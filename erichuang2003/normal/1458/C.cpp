#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int T,n,m;

struct Matrix
{
	int r,c;
	int a[4][4];
	
	Matrix (int R = 0,int C = 0)
	{
		r = R;
		c = C;
		memset(a,0,sizeof(a));
	}
	
	Matrix operator * (const Matrix &p)const
	{
		Matrix res(r,p.c);
		for (int i = 0;i < r;i++)
			for (int j = 0;j < p.c;j++)
				for (int k = 0;k < c;k++)
					(res.a[i][j] += a[i][k] * p.a[k][j]) %= n;
		return res;
	}
	
	void print()
	{
		for (int i = 0;i < r;i++,cout << endl)
			for (int j = 0;j < c;j++)
				cout << a[i][j] << ' ';
	}
}st,trans,I;

int a[MAXN][MAXN];
int ans[MAXN][MAXN];

char s[100005];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
				scanf("%d",&a[i][j]);
		scanf("%s",s + 1);
		trans = I = Matrix(4,4);
		I.a[0][0] = I.a[1][1] = I.a[2][2] = I.a[3][3] = 1;
		trans = I;
		for (int i = 1;i <= m;i++)
		{
			Matrix t = Matrix(4,4);
			if (s[i] == 'R')
			{
				t = I;
				t.a[3][1] = 1;
				trans = trans * t;
			}
			if (s[i] == 'L')
			{
				t = I;
				t.a[3][1] = n - 1;
				trans = trans * t;
			}
			if (s[i] == 'D')
			{
				t = I;
				t.a[3][0] = 1;
				trans = trans * t;
			}
			if (s[i] == 'U')
			{
				t = I;
				t.a[3][0] = n - 1;
				trans = trans * t;
			}
			if (s[i] == 'I')
			{
				t.a[0][0] = 1;
				t.a[1][2] = t.a[2][1] = 1;
				t.a[3][3] = 1;
				trans = trans * t;
			}
			if (s[i] == 'C')
			{
				t.a[1][1] = 1;
				t.a[0][2] = t.a[2][0] = 1;
				t.a[3][3] = 1;
				trans = trans * t;
			}
		}
		for (int i = 0;i < n;i++)
			for (int j = 0;j < n;j++)
			{
				st = Matrix(1,4);
				st.a[0][0] = i;
				st.a[0][1] = j;
				st.a[0][2] = a[i][j] - 1;
				st.a[0][3] = 1;
				st = st * trans;
				ans[st.a[0][0]][st.a[0][1]] = st.a[0][2];
			}
		for (int i = 0;i < n;i++,printf("\n"))
			for (int j = 0;j < n;j++)
				printf("%d ",ans[i][j] + 1);
		printf("\n");
	}
	return 0;
}