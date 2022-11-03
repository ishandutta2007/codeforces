#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 9999;
const int MAXSIZE = 100;
const int DLEN = 4;

class BigNum
{
private:
	int a[800];    //
	int len;       //
public:
	BigNum() { len = 1; memset(a, 0, sizeof(a)); }   //
	BigNum(const int);       //int
	BigNum(const char*);     //
	BigNum(const BigNum&);  //
	BigNum& operator=(const BigNum&);   //

	friend istream& operator>>(istream&, BigNum&);   //
	friend ostream& operator<<(ostream&, BigNum&);   //

	BigNum operator+(const BigNum&) const;   //
	BigNum operator-(const BigNum&) const;   //
	BigNum operator*(const BigNum&) const;   //
	BigNum operator/(const int&) const;    //

	BigNum operator^(const int&) const;    //n
	int    operator%(const int&) const;    //int
	bool   operator>(const BigNum& T)const;   //
	bool   operator>(const int& t)const;      //int

	void print();       //
};
BigNum::BigNum(const int b)     //int
{
	int c, d = b;
	len = 0;
	memset(a, 0, sizeof(a));
	while (d > N)
	{
		c = d - (d / (N + 1)) * (N + 1);
		d = d / (N + 1);
		a[len++] = c;
	}
	a[len++] = d;
}
BigNum::BigNum(const char* s)     //
{
	int t, k, index, l, i;
	memset(a, 0, sizeof(a));
	l = strlen(s);
	len = l / DLEN;
	if (l % DLEN)
		len++;
	index = 0;
	for (i = l - 1; i >= 0; i -= DLEN)
	{
		t = 0;
		k = i - DLEN + 1;
		if (k < 0)
			k = 0;
		for (int j = k; j <= i; j++)
			t = t * 10 + s[j] - '0';
		a[index++] = t;
	}
}
BigNum::BigNum(const BigNum& T) : len(T.len)  //
{
	int i;
	memset(a, 0, sizeof(a));
	for (i = 0; i < len; i++)
		a[i] = T.a[i];
}
BigNum& BigNum::operator=(const BigNum& n)   //
{
	int i;
	len = n.len;
	memset(a, 0, sizeof(a));
	for (i = 0; i < len; i++)
		a[i] = n.a[i];
	return *this;
}
istream& operator>>(istream& in, BigNum& b)   //
{
	char ch[MAXSIZE * 4];
	int i = -1;
	in >> ch;
	int l = strlen(ch);
	int count = 0, sum = 0;
	for (i = l - 1; i >= 0;)
	{
		sum = 0;
		int t = 1;
		for (int j = 0; j < 4 && i >= 0; j++, i--, t *= 10)
		{
			sum += (ch[i] - '0') * t;
		}
		b.a[count] = sum;
		count++;
	}
	b.len = count++;
	return in;

}
ostream& operator<<(ostream& out, BigNum& b)   //
{
	int i;
	cout << b.a[b.len - 1];
	for (i = b.len - 2; i >= 0; i--)
	{
		cout.width(DLEN);
		cout.fill('0');
		cout << b.a[i];
	}
	return out;
}

BigNum BigNum::operator+(const BigNum& T) const   //
{
	BigNum t(*this);
	int i, big;      //
	big = T.len > len ? T.len : len;
	for (i = 0; i < big; i++)
	{
		t.a[i] += T.a[i];
		if (t.a[i] > N)
		{
			t.a[i + 1]++;
			t.a[i] -= N + 1;
		}
	}
	if (t.a[big] != 0)
		t.len = big + 1;
	else
		t.len = big;
	return t;
}
BigNum BigNum::operator-(const BigNum& T) const   //
{
	int i, j, big;
	bool flag;
	BigNum t1, t2;
	if (*this > T)
	{
		t1 = *this;
		t2 = T;
		flag = 0;
	}
	else
	{
		t1 = T;
		t2 = *this;
		flag = 1;
	}
	big = t1.len;
	for (i = 0; i < big; i++)
	{
		if (t1.a[i] < t2.a[i])
		{
			j = i + 1;
			while (t1.a[j] == 0)
				j++;
			t1.a[j--]--;
			while (j > i)
				t1.a[j--] += N;
			t1.a[i] += N + 1 - t2.a[i];
		}
		else
			t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while (t1.a[t1.len - 1] == 0 && t1.len > 1)
	{
		t1.len--;
		big--;
	}
	if (flag)
		t1.a[big - 1] = 0 - t1.a[big - 1];
	return t1;
}

BigNum BigNum::operator*(const BigNum& T) const   //
{
	BigNum ret;
	int i, j, up;
	int temp, temp1;
	for (i = 0; i < len; i++)
	{
		up = 0;
		for (j = 0; j < T.len; j++)
		{
			temp = a[i] * T.a[j] + ret.a[i + j] + up;
			if (temp > N)
			{
				temp1 = temp - temp / (N + 1) * (N + 1);
				up = temp / (N + 1);
				ret.a[i + j] = temp1;
			}
			else
			{
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if (up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
BigNum BigNum::operator/(const int& b) const   //
{
	BigNum ret;
	int i, down = 0;
	for (i = len - 1; i >= 0; i--)
	{
		ret.a[i] = (a[i] + down * (N + 1)) / b;
		down = a[i] + down * (N + 1) - ret.a[i] * b;
	}
	ret.len = len;
	while (ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
int BigNum::operator %(const int& b) const    //int
{
	int i, d = 0;
	for (i = len - 1; i >= 0; i--)
	{
		d = ((d * (N + 1)) % b + a[i]) % b;
	}
	return d;
}
BigNum BigNum::operator^(const int& n) const    //n
{
	BigNum t, ret(1);
	int i;
	if (n < 0)
		exit(-1);
	if (n == 0)
		return 1;
	if (n == 1)
		return *this;
	int m = n;
	while (m > 1)
	{
		t = *this;
		for (i = 1; i << 1 <= m; i <<= 1)
		{
			t = t * t;
		}
		m -= i;
		ret = ret * t;
		if (m == 1)
			ret = ret * (*this);
	}
	return ret;
}
bool BigNum::operator>(const BigNum& T) const   //
{
	int ln;
	if (len > T.len)
		return true;
	else if (len == T.len)
	{
		ln = len - 1;
		while (a[ln] == T.a[ln] && ln >= 0)
			ln--;
		if (ln >= 0 && a[ln] > T.a[ln])
			return true;
		else
			return false;
	}
	else
		return false;
}
bool BigNum::operator >(const int& t) const    //int
{
	BigNum b(t);
	return *this > b;
}

void BigNum::print()    //
{
	int i;
	printf("%d", a[len - 1]);
	for (i = len - 2; i >= 0; i--)
	{
		printf("%0*d", DLEN, a[i]);
	}
	puts("");
}
BigNum ans;
int flag[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> mc;
	vector<int> v;
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		int x;
		cin >> str >> x;
		x++;
		if (str == "sell") v.push_back(-x);
		else v.push_back(x);
	}
	reverse(v.begin(), v.end());
	string str(2010, '0');
	while (1)
	{
		int id1 = -1;
		int cur = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (flag[i]) continue;
			if (v[i] < cur)
			{
				cur = v[i];
				id1 = i;
			}
		}
		if (id1 == -1) break;
		int id2 = -1;
		for (int i = id1; i < v.size(); i++)
		{
			if (flag[i]) break;
			if (v[i] + cur == 0)
			{
				id2 = i;
				break;
			}
		}
		if (id2 == -1)
		{
			v[id1] = 0;
			continue;
		}
		str[v[id2] - 1] = '1';
		for (int i = id1; i <= id2; i++)
			flag[i] = 1;
	}
	while (str.length() > 1 && str.back() == '0') str.pop_back();
	reverse(str.begin(), str.end());
	for (auto& c : str)
	{
		ans = ans * 2;
		if (c == '1')
			ans = ans + 1;
	}
	ans.print();
	return 0;
}