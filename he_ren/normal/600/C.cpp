#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 2e5 + 5;
using namespace std;

char s[MAXN];
int cnt[30];

int main(void)
{
	scanf("%s",s);
	int n=strlen(s);
	
	for(int i=0; i<n; ++i) ++cnt[s[i]-'a'];
	
	for(int i=0; i<26; ++i) if(cnt[i]&1)
		for(int j=25; j>i; --j) if(cnt[j]&1)
		{
			++cnt[i]; --cnt[j];
			break;
		}
	
	for(int i=0; i<26; ++i)
		for(int j=1; j<=(cnt[i]>>1); ++j) putchar(i+'a');
	
	for(int i=0; i<26; ++i) if(cnt[i]&1)
	{
		putchar(i+'a'); break;
	}
	
	for(int i=25; i>=0; --i)
		for(int j=1; j<=(cnt[i]>>1); ++j) putchar(i+'a');
	return 0;
}