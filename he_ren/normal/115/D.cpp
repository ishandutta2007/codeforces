#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int mod = 1e6 + 3;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline int get_id(char c){ return c >= '0' && c <= '9'? 0: c == '+' || c == '-'? 1: 2;}

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	vector<int> vec;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && (get_id(s[i]) > 0) == (get_id(s[j]) > 0)) ++j;
		if(!get_id(s[i])){ vec.push_back(0); continue;}
		if(j > n) return printf("0"), 0;
		
		if(i == 1 && get_id(s[i]) == 2)
			return printf("0"), 0;
		for(int k=i+1; k<j; ++k)
			if(get_id(s[k]) == 2)
				return printf("0"), 0;
		
		vec.insert(vec.end(), j-i, 1);
	}
	
	int tot = (int)vec.size();
	
	static int f[MAXN][MAXN];
	f[0][0] = 1;
	for(int i=1; i<=tot; ++i)
	{
		if(vec[i-1])
		{
			for(int j=0; j<i; ++j)
				f[i][j+1] = f[i-1][j];
		}
		else
		{
			int sum = 0;
			for(int j=i-1; j>=0; --j)
				add_mod(sum, f[i-1][j]),
				f[i][j] = sum;
		}
	}
	
	printf("%d",f[tot][0]);
	return 0;
}