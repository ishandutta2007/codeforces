#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool ask(vector<int> s)
{
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

void split(const vector<int> &A,vector<int> &L,vector<int> &R)
{
	int k = (int)A.size() / 2;
	L = vector<int>(A.begin(), A.begin() + k);
	R = vector<int>(A.begin() + k, A.end());
}

int main(void)
{
	int n;
	scanf("%d",&n);
	
	vector<int> A(n);
	iota(A.begin(), A.end(), 1);
	
	while(A.size() >= 4)
	{
		vector<int> L,R;
		split(A, L, R);
		
		if(!ask(L)) swap(L, R);
		
		vector<int> x, y;
		split(R, x, y);
		
		if(!ask(x)) swap(x, y);
		
		A = L;
		A.insert(A.end(), x.begin(), x.end());
	}
	
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
		if(ask({A[0]}))
		{
			answer(A[0]);
			if(ask({A[1]}))
				answer(A[1]);
			else
				answer(A[2]);
			return 0;
		}
		if(ask({A[0]}))
		{
			answer(A[0]);
			if(ask({A[1]}))
				answer(A[1]);
			else
				answer(A[2]);
			return 0;
		}
		answer(A[1]);
		answer(A[2]);
	}
	return 0;
}