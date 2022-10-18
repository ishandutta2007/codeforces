#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#include <ctime>

#define ll long long

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);}
int lcm(int a,int b)
{
	if (a==0||b==0) return a+b;
	return a/gcd(a,b)*b;
}

int mod=2520;
vector <int> v;
int index[2522]={0},nmod[2522][10]={0},nlcm[2522][2522]={0},gmod[2522][21]={0};
ll mem[21][2520][50]={0};

ll calc(ll n)
{
	ll ans=0;
	vector <int> nums;
	while(n>0)
	{
		nums.push_back(n%10);
		n/=10;
	}
	reverse(nums.begin(),nums.end());
	int bmod=0,blcm=1;
	for(int i=0;i<nums.size();i++)
	{
		for(int j=0;j<nums[i];j++)
		{
			for(int kmod=0;kmod<2520;kmod++)
				for(int klcm=0;klcm<v.size();klcm++)
					if (((gmod[nmod[bmod][j]][nums.size()-1-i]+kmod)%mod)%nlcm[v[klcm]][nlcm[blcm][j]]==0) ans+=mem[nums.size()-1-i][kmod][klcm];
		}
		bmod=nmod[bmod][nums[i]];
		blcm=nlcm[blcm][nums[i]];
	}
	return ans;
}
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	for(int i=0;i<(1<<10);i++)
	{
		int cur=1;
		for(int j=0;j<10;j++)
			if (i&(1<<j)) cur=lcm(cur,j);
		index[cur]=1;
	}
	int last=0;
	index[1]=true;
	for(int i=1;i<=2520;i++)
		if (index[i])
		{
			v.push_back(i);
			index[i]=last++;
		}
	for(int i=0;i<2520;i++)
		for(int j=0;j<10;j++)
			nmod[i][j]=(i*10+j)%mod;
	ll step10[22]={0};
	step10[0]=1;
	for(int i=1;i<=20;i++)
		step10[i]=(step10[i-1]*10)%mod;
	for(int i=0;i<=2520;i++)
		for(int t=0;t<20;t++)
			gmod[i][t]=(i*step10[t])%mod;
	for(int i=0;i<=2520;i++)
		for(int j=0;j<=2520;j++)
			if (j!=0) nlcm[i][j]=lcm(i,j);
			else nlcm[i][j]=i;
	for(int i=0;i<=20;i++)
		for(int bmod=0;bmod<2520;bmod++)
			for(int ind=0;ind<v.size();ind++)
				mem[i][bmod][ind]=0;
	mem[0][0][0]=1;
	for(int i=0;i<=19;i++)
	{
		for(int bmod=0;bmod<2520;bmod++)
		{
			for(int ind=0;ind<v.size();ind++)
			{
				if (mem[i][bmod][ind]==0) continue;
				for(int j=0;j<10;j++)
				{
					mem[i+1][nmod[bmod][j]][index[nlcm[v[ind]][j]]]+=mem[i][bmod][ind];
				}
			}
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		ll l,r;
		cin >> l >> r;
		cout << calc(r+1)-calc(l) << endl;
	}
//	for(int i=1;i<=100;i++)
//		cout << i << "	" << calc(i) << endl;
	return 0;
}