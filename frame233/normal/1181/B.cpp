//Author --Frame

#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}
const int N=100005;
int n,a[N];

struct big_num
{
	int len, num[N];
	void clear()
	{
		len = 0;
		memset(num, 0, sizeof(num));
		return;
	}
}b, c, ans;

big_num add(int x)
{
	b.clear(), c.clear(), ans.clear();
	b.len = x - 1, c.len = n - x + 1;
	for(int i = 1; i <= b.len; i++) b.num[i] = a[x - i];
	for(int i = x; i <= n; i++) c.num[i - x + 1] = a[n - i + x];
	ans.len = max(b.len, c.len);
	for(int i = 1; i <= ans.len; i++)
	{
		ans.num[i] += b.num[i] + c.num[i];
		ans.num[i + 1] += ans.num[i] / 10;
		ans.num[i] %= 10;
	}
	while(ans.num[ans.len + 1]) ans.len++;
	return ans;
}

bool checkmax(big_num x, big_num y)
{
	if(x.len != y.len) return x.len > y.len;
	else 
	{
		for(int i = x.len; i >= 1; i--)
		{
			if(x.num[i] != y.num[i]) return x.num[i] > y.num[i];
		}
		return 1;
	}
}

bool check(int x, int y)
{
	return checkmax(add(x), add(y));
}

int main()
{
	read(n);
	for(int i = 1; i <= n; i++)
	{
		char c;
		std::cin >> c;
		a[i] = c - '0';
	}
	int k = n / 2 + 1;
	if(a[k] == 0) 
	{
		int k1 = k - 1, k2 = k + 1;
		while(a[k1] == 0 && k1 >= 1) k1--;
		while(a[k2] == 0 && k2 <= n) k2++;
		bool flag = check(k1, k2);
		if(flag == 1) k = k2;
		else k = k1;
	}
	else if(n % 2 == 1)
	{
		if(a[k + 1] != 0) 
		{
			if(check(k, k + 1)) k++;
		}
	}
	big_num tmp = add(k);
	for(int i = tmp.len; i >= 1; i--) std::cout << tmp.num[i];
	printf("\n");
	return 0;
}