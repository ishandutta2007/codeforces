#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}

using str = std::string;

const int MN = 310;

int N, p[MN], f, ini;
std::vector<str> a;
bool ok[MN][MN];

int dp[MN][MN];

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		str s;
		std::cin >> s;
		a.push_back(s);
		p[i+1] = p[i] + s.size();
	}
	ini=f=p[N]+N-1;
	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
			if(a[i]==a[j])
				ok[i][j]=ok[j][i]=1;
	for(int i=N-1;i>=0;--i)
		for(int j=i+1;j<N;++j)
		{
			for(int k=0;i+k<j;)
			{
				if(!ok[i+k][j+k]) break;
				++k;
				ckmax(dp[i][k], dp[j][k]+1);
				int v = dp[i][k];
				//printf("%d\n", v);
				if(v>=1)
					ckmin(f, ini+(v+1)*(1-(p[i+k]-p[i])));
			}
		}
	printf("%d\n", f);
}