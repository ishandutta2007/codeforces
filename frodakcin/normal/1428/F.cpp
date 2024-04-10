#include <cstdio>
#include <stack>

const int MN = 5e5+10;

using ll = long long;

int N;
ll ans, cur;
char s[MN];
struct info
{
	public:
		int f, x;
};

std::stack<info> st;

ll c2(int v) {return (ll)v*(v+1)/2;}

int main()
{
	st.push({MN, -1});
	scanf("%d %s", &N, s);
	for(int i=0,j;i<N;)
		if(s[i]=='0')
			ans+=cur, ++i;
		else
		{
			for(j=i;j<N && s[j]=='1';++j)
			{
				for(;st.top().f <= j-i+1;)
				{
					info v=st.top(); st.pop();
					cur -= (ll)(v.x-st.top().x)*v.f;
				}
				cur += (ll)(i-st.top().x)*(j-i+1);
				st.push({j-i+1, i});
				ans += cur + c2(j-i); // j-i+1 accounted for
			}
			for(++i;i<j;++i)
				st.push({j-i, i}), cur += j-i;
		}
	printf("%lld\n", ans);
	return 0;
}