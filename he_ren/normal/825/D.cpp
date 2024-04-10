#include<cstdio>
#include<cstring>
typedef long long ll;
const int MAXN = 1e6 + 5;

char s[MAXN],t[MAXN];
int ps[30],pt[30],cnt=0;
int nd[30];

inline bool chk(int mid)
{
	ll need=0;
	for(int i=0; i<26; ++i)
		if(ps[i] < (ll)pt[i]*mid)
		{
			need += (ll)pt[i]*mid-ps[i];
			if(need>cnt) return 0;
		}
	return 1;
}

int main(void)
{
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1), m=strlen(t+1);
	
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='?') ++cnt;
		else ++ps[s[i]-'a'];
	}
	
	for(int i=1; i<=m; ++i)
		++pt[t[i]-'a'];
	
	int l=0, r=n;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	
	for(int i=0; i<26; ++i)
		if(ps[i] < pt[i]*l)
			nd[i] += pt[i]*l-ps[i];
	
	for(int i=1; i<=n; ++i) if(s[i]=='?')
	{
		for(int j=0; j<26; ++j)
			if(nd[j])
			{
				s[i]=j+'a';
				--nd[j];
				break;
			}
		if(s[i]=='?') s[i]='a';
	}
	printf("%s",s+1);
	return 0;
}