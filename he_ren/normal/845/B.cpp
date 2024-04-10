#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 6 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}
inline void chk_min(int &a,int b){ if(a>b) a=b;}

char s[MAXN];

inline int gao_d(int x)
{
	if(!x) return 0;
	
	for(int i=3; i>=1; --i)
	{
		if(x<=s[i]) return 3-i+1;
		x -= s[i];
	}
	return inf;
}

inline int gao_u(int x)
{
	if(!x) return 0;
	
	for(int i=4; i<=6; ++i)
	{
		if(s[i]+x <= 9) return i-3;
		x -= 9-s[i];
	}
	return inf;
}

int main(void)
{
	scanf("%s",s+1);
	for(int i=1; i<=6; ++i) s[i]-='0';
	
	int a=0, b=0;
	for(int i=1; i<=3; ++i)
		a+=s[i], b+=s[i+3];
	
	if(a<b)
	{
		swap(a,b);
		for(int i=1; i<=3; ++i) swap(s[i],s[i+3]);
	}
	sort(s+1,s+3+1);
	sort(s+4,s+6+1);
	
	int lft=a-b, ans=inf;
	for(int i=0; i<=lft; ++i)
		chk_min( ans, gao_d(i)+gao_u(lft-i) );
	printf("%d",ans);
	return 0;
}