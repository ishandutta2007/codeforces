#include <iostream>

#define dat cin
#define sol cout

using namespace std;

int count_bits(int i)
{
	int num=0;
	while(i>0)
	{
		num+=i&1;
		i>>=1;
	}
	return num;
}

int bit(int x,int i)
{
	return x&(1<<i);
}

int first_bit(int x)
{
	int ans=0;
	while(x%2==0)
	{
		x/=2;
		ans++;
	}
	return ans;
}

long long dp[1<<20][20]={0};

int main()
{
//	ifstream dat("input.txt");
//	ofstream sol("output.txt");
	long n,m,a,b;
	dat >> n >> m;
	bool D[21][21]={0};
	for(int i=0;i<m;i++)
	{
		dat >> a >> b;
		D[--a][--b]=true;
		D[b][a]=true;
	}
	for(int mask=1;mask<(1<<n);mask++)
	{
		for(int i=0;i<n;i++)
		{
			if (bit(mask,i)==0) continue;
			if (count_bits(mask)==1)
			{
				dp[mask][i]=1;
				continue;
			}
			if (count_bits(mask)<2) continue;
			if (first_bit(mask)==i) continue;
			for(int j=0;j<n;j++)
			{
				if (mask&(1<<j)&&D[j][i])
				{
					dp[mask][i]+=dp[mask&(~(1<<i))][j];
				}
			}
		}
	}
	long long ans=0;
	for(int mask=1;mask<(1<<n);mask++)
	{
		if (count_bits(mask)<3) continue;
//		sol << mask << "	";
		for(int i=0;i<n;i++)
		{
//			sol << mask << "	" << first_bit(mask)+1 << "	" << i+1 << "	" << dp[mask][i] << "\n";
			if (D[first_bit(mask)][i]) ans+=dp[mask][i];
		}
//		sol << endl;
	}
	sol << ans/2 << endl;
	return 0;
}