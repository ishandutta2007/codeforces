#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=100010;

char s[MAXN];
int sum[MAXN];
int n;
int best, bi, bj;

int p[MAXN];
int t;

bool match(char a, char b) {
	return (a=='['&&b==']') || (a=='('&&b==')');
}
int zi[MAXN], zj[MAXN], zn;
void update(int i, int j) {
	while(zn>0 && i<zi[zn])
		--zn;
	while(zn>0 && zj[zn]+1==i)
		i=zi[zn], --zn;
	if(sum[j]-sum[i-1]>best) {
		best=sum[j]-sum[i-1];
		bi=i, bj=j;
	}
	++zn; zi[zn]=i, zj[zn]=j;
}

int main() {
	scanf("%s", s+1);
	n=strlen(s+1);
	sum[0]=0;
	for(int i=1; i<=n; ++i)
		sum[i]=sum[i-1]+(s[i]=='[');

	best=0; bi=1; bj=0;
	t=0; 
	p[t]=0; s[n+1]='x';
	zn=0;
	for(int i=1; i<=n+1; ++i)
		if(s[i]=='[' || s[i]=='(')
			p[++t]=i;
		else
			if(t>0 && match(s[p[t]],s[i]))
				update(p[t], i), --t;
			else {
				t=0;
			}
	printf("%d\n", best);
	for(int i=bi; i<=bj; ++i) printf("%c", s[i]);
	printf("\n");
	return 0;
}