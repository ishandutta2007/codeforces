#include <cstdio>
#include <cassert>

using ll = long long;

//1W, 1L, 2W, 2L => 0,1,2,3 bits
const int MT = 1e5+10;
int T, v[10];
ll s[MT], e[MT];

int get(int a, int b)//player 1 can choose a or b
{
	int f=0;
	f|=(a>>2&1|b>>2&1)<<0;//1W if 2Wa or 2Wb
	f|=(a>>3&1|b>>3&1)<<1;//1L if 2La or 2Lb
	f|=(a>>0&b>>0&1)<<2;//2W if 1Wa and 1Wb
	f|=(a>>1&b>>1&1)<<3;//2L if 1La and 1Lb
	return f;
}
int flip(int a){return a>>2|(a&3)<<2;}
int main()
{
	scanf("%d", &T);
	for(int i=0;i<T;++i)
		scanf("%lld%lld", s+i, e+i);
	int p=0b0110;//+2L -2W -1L +1W
	for(int i=T-1;i>=0;--i)
	{
		p=flip(p);
		int n=p, j=p;//ans for e[i]; n = next (increment), j = jump (double)
		for(ll x=e[i],nx;;x=nx)
		{
			nx = x/2;
			v[0]=get(j,n);
			v[1]=get(j,v[0]);
			//printf("%d: %d %d\n", i, v[0], v[1]);
			assert(v[0] == get(j, v[1]));//cyclic for odd/even
			if(s[i] > nx)
			{
				p = v[(s[i]^x)&1];
				break;
			}
			else
			{
				//printf("XNX %lld %lld\n", x, nx);
				n = v[(nx+1^x)&1];//CHECK HERE
				j = v[x&1];
			}
		}
		//printf("%d: %d\n", i, p);
	}
	printf("%d %d\n", p&1, p>>1&1);
	return 0;
}