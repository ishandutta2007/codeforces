#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=200010;

char s[MAXN], t[MAXN];
int c[MAXN][26];
int ls, lt;
int ml[MAXN], mr[MAXN];

int main() {
	scanf("%s%s", s+1,t+1);
	ls=strlen(s+1), lt=strlen(t+1);
	memset(c[0], 0, sizeof(c[0]));
	for(int i=1; i<=lt; ++i) {
		for(int j=0; j<26; ++j) c[i][j]=c[i-1][j];
		c[i][t[i]-'a']++;
	}

	ml[0]=0;
	for(int i=1; i<=ls; ++i) {
		ml[i]=ml[i-1];
		if(ml[i]<lt && s[i]==t[ml[i]+1])
			++ml[i];
	}
	mr[ls+1]=lt+1;
	for(int i=ls; i>=1; --i) {
		mr[i]=mr[i+1];
		if(mr[i]>1 && s[i]==t[mr[i]-1])
			--mr[i];
	}

	bool flag=true;
	for(int i=1; i<=ls; ++i) {
		int le=max(1, mr[i+1]-1);
		int ri=min(lt, ml[i-1]+1);
		//printf("i=%d le=%d ri=%d\n", i,le,ri);
		if(le>ri || c[ri][s[i]-'a']-c[le-1][s[i]-'a']<=0) {
			flag=false;
			break;
		}
	}
	printf("%s\n", flag?"Yes":"No");

	return 0;
}