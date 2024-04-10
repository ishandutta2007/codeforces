#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int MAXM = 2e2 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

char s[MAXM];
int a[MAXM];

int nxt[MAXM][2];
int f[MAXN][MAXM][MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	int m = strlen(s+1);
	n *= 2;
	
	for(int i=1; i<=m; ++i) a[i] = s[i] == ')';
	for(int i=0; i<=m; ++i)
		for(int j=0; j<=1; ++j)
		{
			if(i == m){ nxt[i][j] = m; continue;}
			if(a[i+1] == j){ nxt[i][j] = i + 1; continue;}
			vector<int> vec(a+1, a+i+1);
			vec.push_back(j);
			
			for(int k=i; k>=1; --k)
				if(vector<int>(a+1,a+k+1) == vector<int>(vec.end() - k, vec.end()))
				{
					nxt[i][j] = k;
					break;
				}
		}
	
	
	f[0][0][0] = 1;
	for(int i=0; i<n; ++i)
		for(int j=0; j<=m; ++j)
			for(int k=0; k<=i; ++k) if(f[i][j][k])
				for(int t=0; t<=1; ++t)
				{
					if(k == 0 && t == 1) continue;
					int nj = nxt[j][t];
					int nk = t? k - 1: k + 1;
					add_mod(f[i+1][nj][nk], f[i][j][k]);
				}
	
	printf("%d",f[n][m][0]);
	return 0;
}