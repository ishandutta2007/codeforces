#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXL = 26 + 5;

struct Data
{
	int to, k, x, y;// to = k * x + y
	Data(void){}
	Data(int to,int k,int x,int y=-1): to(to), k(k), x(x), y(y) {}
	inline void print(void)
	{
		printf("lea e%cx, ",to + 'a');
		if(y == -1) printf("[%d*e%cx]\n", k, x + 'a');
		else printf("[e%cx + %d*e%cx]\n",y + 'a', k, x + 'a');
	}
};

int n, lim = 0, val[MAXL];
Data seq[MAXL];
void dfs(int pos)
{
	if(pos > lim)
	{
		if(val[lim] == n)
		{
			printf("%d\n",lim);
			for(int i=1; i<=lim; ++i) seq[i].print();
			exit(0);
		}
		return;
	}
	
	for(int i=-1; i<pos; ++i)
		for(int j=0; j<pos; ++j)
			for(int k=1; k<=8; k*=2)
			{
				val[pos] = (i==-1? 0: val[i]) + val[j] * k;
				seq[pos] = Data(pos, k, j, i);
				dfs(pos+1);
			}
}

int main()
{
	scanf("%d",&n);
	if(n==1) return printf("0"), 0;
	
	val[0] = 1;
	while(1) ++lim, dfs(1);
	return 0;
}