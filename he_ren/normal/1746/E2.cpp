#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;

#ifdef He_Ren

int askcnt = 0;
mt19937 gen((unsigned long long)new char ^ time(0));
bool ask(vector<int>)
{
	++askcnt;
	return gen() % 2;
}

void answer(int x)
{
	printf("answer! x = %d, askcnt = %d\n",x,askcnt);
}

#else

bool ask(vector<int> s)
{
	if(!s.size()) return 0;
	printf("? %d ",(int)s.size());
	for(int t: s)
		printf("%d ",t);
	printf("\n");
	fflush(stdout);
	
	static char ans[10];
	scanf("%s",ans);
	return ans[0] == 'Y';
}

void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	
	static char ans[10];
	scanf("%s",ans);
	if(ans[1] == ')') exit(0);
}

#endif

void split(const vector<int> &A,vector<int> &L,vector<int> &R,int k)
{
	L = vector<int>(A.begin(), A.begin() + k);
	R = vector<int>(A.begin() + k, A.end());
}
void merge(vector<int> &A,const vector<int> &R)
{
	A.insert(A.end(), R.begin(), R.end());
}

const int lim = 50;
array<int,3> dp[lim][lim];

void solve(void)
{
	int n;
#ifdef He_Ren
	n = 1e5;
	askcnt = 0;
#else
	scanf("%d",&n);
#endif
	
	vector<int> A(n), B;
	iota(A.begin(), A.end(), 1);
	
	vector<pii> s;
	
	while(A.size() + B.size() >= 4 || (A.size() + B.size() == 3 && B.size() != 1))
	{
		s.emplace_back(A.size(), B.size());
		
		vector<int> LA, RA, LB, RB;
		int sA = (int)A.size(), sB = (int)B.size();
		int kA, kB;
		
		if(sA < lim && sB < lim && dp[sA][sB][0] != inf)
			kA = dp[sA][sB][1], kB = dp[sA][sB][2];
		else
			kA = (sA + 1) / 2, kB = sB / 2;
		
		split(A, LA, RA, kA);
		split(B, LB, RB, kB);
		
		vector<int> tmp;
		merge(tmp = LA, LB);
		
		if(!ask(tmp)) swap(LA, RA), swap(LB, RB);
		
		B = RA;
		A = LA;
		merge(A, LB);
	}
	
	merge(A, B);
	
	if(A.size() == 1)
	{
		answer(A[0]);
	}
	else if(A.size() == 2)
	{
		answer(A[0]);
		answer(A[1]);
	}
	else
	{
		if(ask({A[2]}))
		{
			answer(A[2]);
			if(ask({A[0]}))
				answer(A[0]);
			else
				answer(A[1]);
		}
		else
		{
			answer(A[0]);
			answer(A[1]);
		}
	}

#ifdef He_Ren	
	if(askcnt == 54)
	{
		printf("s:\n");
		for(auto t: s)
			printf("%d %d, dp = %d\n", t.first, t.second, t.first < lim && t.second < lim? dp[t.first][t.second][0]: -1);
		printf("\n");
		exit(0);
	}
#endif
}

int main(void)
{
	for(int i=0; i<lim; ++i)
		for(int j=0; j<lim; ++j)
		{
			dp[i][j] = {inf,-1,-1};
			if(i + j <= 2){ dp[i][j] = {0,-1,-1}; continue;}
			if(i == 2 && j == 1){ dp[i][j] = {2,-1,-1}; continue;}
		}
	
	for(int i=0; i<lim; ++i)
		for(int j=0; j<lim; ++j)
		{
			for(int ii=0; ii<=i; ++ii)
				for(int jj=0; jj<=j; ++jj)
				{
					if(ii + jj >= lim) continue;
					if((i - ii) + (j - jj) >= lim) continue;
					
					array<int,3> cur = {
						max(dp[ii + jj][i - ii][0], dp[(i - ii) + (j - jj)][ii][0]) + 1,
						ii, jj
					};
					
					dp[i][j] = min(dp[i][j], cur);
				}
		}
	
#ifdef He_Ren
	int mxcnt = 0;
	for(int i=1; i<=1000; ++i)
		solve(), mxcnt = max(mxcnt, askcnt);
	printf("mxcnt = %d\n",mxcnt);
#else
	solve();
#endif
	return 0;
}