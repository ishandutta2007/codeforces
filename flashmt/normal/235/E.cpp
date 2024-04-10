#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
const int base = 1<<30;

int p[400],P,pow[400][20],maxPow[400];
map <int,long long> f[400][2020];

long long dp(int i,int A,int B,int C)
{
	if (i<0) return 1;
	if (A<B) swap(A,B);
	if (A<C) swap(A,C);
	if (B<C) swap(B,C);
	if (f[i][A].count(B*2001+C)) return f[i][A][B*2001+C];
	
	long long res=0;
	
	for (int x=0;pow[i][x]<=A;x++)
		for (int y=0;pow[i][y]<=B;y++)
			for (int z=0;pow[i][z]<=C;z++)
			{
				res+=dp(i-1,A/pow[i][x],B/pow[i][y],C/pow[i][z])*(x+y+z+1);
				res%=base;
			}
			
	return f[i][A][B*2001+C]=res;
}

int main()
{
	for (int i=2;i<2000;i++)
	{
		int isPrime=1;
		for (int j=2;j*j<=i;j++)
			if (i%j==0) isPrime=0;
		if (!isPrime) continue;
		
		pow[P][0]=1;
		for (int j=1;;j++)
		{
			pow[P][j]=pow[P][j-1]*i;
			if (pow[P][j]>2000) break;
		}
		p[P++]=i;
	}
	
	int A,B,C;
	cin >> A >> B >> C;
	cout << dp(P-1,A,B,C) << endl;
}