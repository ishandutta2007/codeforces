#include<bits/stdc++.h>
#define SIZE 100005
#define BT 1024*128*2
#define MX 11

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct BIT
{
	vector <int> bit;
	
	void init(int N)
	{
		bit.resize(N+2,0);
	}
	void add(int k,int x)
	{
		k++;
		while(k<bit.size())
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		k++;
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t)
	{
		return get(t)-get(s-1);
	}
};
BIT bit[MX][MX][4];
int A[SIZE];
char str[SIZE];
int n;

int ctoi(char c)
{
	if(c=='A') return 0;
	if(c=='C') return 1;
	if(c=='G') return 2;
	return 3;
}
void init()
{
	for(int i=1;i<MX;i++)
	{
		for(int j=0;j<i;j++)
		{
			for(int t=0;t<4;t++)
			{
				bit[i][j][t].init(n/i+5);
			}
		}
	}
}
void ins(int p)
{
	for(int i=1;i<MX;i++)
	{
		bit[i][p%i][A[p]].add(p/i,1);
	}
}
void rem(int p)
{
	for(int i=1;i<MX;i++)
	{
		bit[i][p%i][A[p]].add(p/i,-1);
	}
}
int main()
{
	scanf("%s",&str);
	n=strlen(str);
	init();
	for(int i=0;i<n;i++)
	{
		A[i]=ctoi(str[i]);
		ins(i);
	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int x;
			scanf("%d %s",&x,&str);x--;
			rem(x);
			A[x]=ctoi(str[0]);
			ins(x);
		}
		else
		{
			int l,r;
			scanf("%d %d %s",&l,&r,&str);l--,r--;
			int ret=0;
			int L=strlen(str);
			for(int j=0;j<L;j++)
			{
				int zan=(l+j)%L;
				int c=ctoi(str[j]);
				int S=(l+j)/L;
				int T=r/L;
				if(T*L+zan>r) T--;
				ret+=bit[L][zan][c].get(S,T);
			}
			printf("%d\n",ret);
		}
	}
	return 0;
}