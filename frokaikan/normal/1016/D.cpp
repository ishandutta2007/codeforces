#include <bits/stdc++.h>
#define SET(x,v) std::memset(x,v,sizeof(x))
const int maxN = 103;
int row[103],col[103],mat[103][103],N,M;
void print()
{
	for (int i=0;i<N;++i)
	for (int j=0;j<M;++j)
		std::printf("%d%c",mat[i][j],j==M-1?'\n':' ');
}
int main()
{
	std::scanf("%d %d",&N,&M);
	int ans = 0;
	for (int i=0;i<N;++i)
	{
		std::scanf("%d",row+i);
		ans ^= row[i];
	}
	for (int i=0;i<M;++i)
	{
		std::scanf("%d",col+i);
		ans ^= col[i];
	}
	if (ans) std::printf("NO\n");
	else
	{
		std::printf("YES\n");
		SET(mat,0);
		if (N<M)
		{
			for (int i=0;i<N-1;++i)
				mat[i][i] = row[i];
			for (int i=0;i<M;++i)
			{
				mat[N-1][i] = col[i];
				if (i<N-1) mat[N-1][i] ^= row[i];
			}
		}
		else
		{
			for (int i=0;i<M-1;++i)
				mat[i][i] = col[i];
			for (int i=0;i<N;++i)
			{
				mat[i][M-1] = row[i];
				if (i<M-1) mat[i][M-1] ^= col[i];
			}
		}
		print();
	}
}