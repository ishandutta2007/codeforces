#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back

const int MAXN=110;

bool like[MAXN];
int n, m;
int st[MAXN], en[MAXN];
int num;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n,&m);
	memset(like, false, sizeof(like));
	for(int i=1; i<=m; ++i) {
		int x; scanf("%d", &x);
		like[x]=true;
	}
	scanf("%d", &num);
	for(int i=1; i<=num; ++i) {
		char buf[99]; scanf("%s", buf);
		st[i]=en[i]=0;
		int d; scanf("%d", &d);
		for(int k=1; k<=d; ++k) {
			int x; scanf("%d", &x);
			if(x!=0) {
				if(like[x]) st[i]++, en[i]++;
			} else
				en[i]++;
		}
		st[i]=max(st[i], d-(n-m));
		en[i]=min(en[i], m);
		//printf("i=%d  [%d,%d]\n",i,st[i],en[i]);
	}
	for(int i=1; i<=num; ++i) {
		bool flag=true;
		for(int j=1; j<=num; ++j)
			if(j!=i && en[j]>st[i])
				flag=false;
		if(flag) {
			printf("0\n"); continue;
		}
		flag=true;
		for(int j=1; j<=num; ++j)
			if(j!=i && st[j]>en[i])
				flag=false;
		if(!flag) {
			printf("1\n"); continue;
		}
		printf("2\n");
	}
	return 0;
}