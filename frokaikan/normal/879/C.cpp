#include <bits/stdc++.h>
#define constant const constexpr
typedef long long ll;
typedef long double db;
typedef std::string str;
constant int maxN = 1e5 + 3;
constant int iinf = 2147483647;
constant ll linf = 9223372036854775807LL;
constant db pi = std::acos(-1.0);
constant db eps = 1e-8;
int N,M;
template <typename T> inline constant T abs(T x){return x>=0?x:-x;}

bool okQ[10];
int nums[10];
char op[2];
int num;
int main()
{
	std::fill_n(okQ,10,false);
	std::fill_n(nums,10,0);
	std::scanf("%d",&N);
	for (int i=0;i<N;++i)
	{
		std::scanf("%s %d",op,&num);
		if (op[0] == '|')
		{
			for (int b=0;b<10;++b,num>>=1)
			if (num&1)
			{
				//std::printf("ok[%d] = true\n",b);
				okQ[b] = true;
				nums[b] = 1;
			}
		}
		else if (op[0] == '&')
		{
			for (int b=0;b<10;++b,num>>=1)
			if (not (num&1))
			{
				//std::printf("ok[%d] = false\n",b);
				okQ[b] = true;
				nums[b] = 0;
			}
		}
		else // op[0] == '^'
		{
			for (int b=0;b<10;++b,num>>=1)
			{
				nums[b] ^= (num&1);
			}
		}
	}
	int AND = 0, OR = 0, XOR = 0;
	int tmp = 1;
	for (int b=0;b<10;++b)
	{
		//std::printf("nums[%d] = %d , %d\n",b, nums[b],okQ[b]);
		if (okQ[b])
		{
			if (nums[b])
			{
				OR |= tmp;
				AND |= tmp;
			}
		}
		else
		{
			AND |= tmp;
			if (nums[b]) XOR |= tmp;
		}
		tmp <<= 1;
	}
	int ops = 0;
	str s = "";
	char tmpp[20];
	if (OR)
	{
		++ops;
		std::sprintf(tmpp,"| %d\n",OR);
		s += tmpp;
	}
	if (AND != 1023)
	{
		++ops;
		std::sprintf(tmpp,"& %d\n",AND);
		s += tmpp;
	}
	if (XOR)
	{
		++ops;
		std::sprintf(tmpp,"^ %d\n",XOR);
		s += tmpp;
	}
	std::printf("%d\n",ops);
	std::cout << s;
}