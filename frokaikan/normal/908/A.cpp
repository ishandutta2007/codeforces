#include <bits/stdc++.h>
#define constant const constexpr
typedef long long ll;
typedef long double db;
typedef std::string str;
constant int maxN = 1e5 + 3;
typedef int intvec[maxN];
typedef ll llvec[maxN];
typedef db dbvec[maxN];
typedef bool boolvec[maxN];
typedef str strvec[maxN];
typedef char c_str[maxN];
template <typename T> inline constant T abs(T x) {return x>=0?x:-x;}

int main()
{
	c_str s;
	std::scanf("%s",s);
	int len = std::strlen(s);
	int ans = 0;
	for (int index=0;index<len;++index)
	{
		char i = s[index];
		if (i <= '9')
		{
			if ((i-'0')&1) ++ans;
		}
		else
		{
			if (i=='a' || i=='e' || i=='i' || i=='o' || i=='u') ++ans;
		}
	}
	std::printf("%d\n",ans);
	return 0;
}