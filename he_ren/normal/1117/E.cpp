#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2e4 + 5;

inline void ask(char s[],char res[])
{
	printf("? %s\n",s);
	fflush(stdout);
	scanf("%s",res);
}

char a[MAXN],b[MAXN],c[MAXN];
char s[MAXN],t[MAXN];

int main(void)
{
	for(int i=0; i<26; ++i)
	{
		int l=i*26*26;
		for(int j=0; j<26*26; ++j)
			a[l+j] = i+'a';
		
		for(int j=0; j<26; ++j)
		{
			for(int k=0; k<26; ++k)
				b[l+j*26+k] = j+'a',
				c[l+j*26+k] = k+'a';
		}
	}
	
	scanf("%s",s);
	int n=strlen(s);
	
	a[n]=b[n]=c[n]=0;
	ask(a,a);
	ask(b,b);
	ask(c,c);
	
	for(int i=0; i<n; ++i)
	{
		int l=0;
		l += (a[i]-'a')*26*26;
		l += (b[i]-'a')*26;
		l += (c[i]-'a');
		t[l]=s[i];
	}
	printf("! %s\n",t);
	fflush(stdout);
	return 0;
}