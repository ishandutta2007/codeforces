#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = (1<<16) + 5;

inline int ask_pos(int i,int j)
{
	printf("%d %d\n",i,j);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
inline int ask_and(int i,int j){ printf("AND "); return ask_pos(i,j);}
inline int ask_or(int i,int j){ printf("OR "); return ask_pos(i,j);}
inline int ask_xor(int i,int j){ printf("XOR "); return ask_pos(i,j);}

int n;
int a[MAXN];

inline void print_ans(void)
{
	printf("! ");
	for(int i=1; i<=n; ++i) printf("%d ",a[i]);
	fflush(stdout);
	exit(0);
}

int main(void)
{
	scanf("%d",&n);
	
	for(int i=2; i<=n; ++i)
		a[i] = ask_xor(1, i);
	
	bool get_fir = 0;
	static int freq[MAXN];
	for(int i=2; i<=n; ++i)
	{
		if(a[i] == 0)
		{
			a[1] = ask_and(1,i);
			get_fir = 1;
			break;
		}
		if(freq[a[i]])
		{
			a[1] = a[i] ^ ask_and(freq[a[i]], i);
			get_fir = 1;
			break;
		}
		freq[a[i]] = i;
	}
	
	if(get_fir)
	{
		for(int i=2; i<=n; ++i)
			a[i] ^= a[1];
		print_ans();
	}
	
	int x,y,z;
	for(int i=2; i<=n; ++i)
	{
		if(a[i] == 3) x = i;
		if(a[i] == 1) y = i;
		if(a[i] == 2) z = i;
	}
	
	int resy = ask_and(x,y), resz = ask_and(x,z);
	a[1] = resy ^ 1;
	a[1] |= (resz&2) ^ 2;
	
	for(int i=2; i<=n; ++i)
		a[i] ^= a[1];
	print_ans();
	return 0;
}