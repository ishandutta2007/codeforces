#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)

const int N=1e6+50;
string a[N];
char str[N];
int b[N];
int cmp(int x,int y) {
	return a[x]<a[y];
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,1,n) {
		scanf("%s",str);
		FOR(j,0,m-1) {
			if(j%2==0) a[i]+=str[j];
			else a[i]+='Z'-str[j]+'A';
		}
		b[i]=i;
	}
	sort(b+1,b+n+1,cmp);
	FOR(i,1,n) printf("%d ",b[i]);
	putchar('\n');
	return 0;
}