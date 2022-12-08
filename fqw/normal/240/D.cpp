#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back

const int MAXN=200010;

int a[MAXN];
int x[MAXN], ans1[MAXN];
int n, mid;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &mid);
	for(int i=1; i<=mid; ++i) scanf("%d", a+i);
	scanf("%d", &n); n+=mid;
	for(int i=mid+1; i<=n; ++i) scanf("%d", a+i);
	int p1=mid, p2=n, cur=n;
	x[n+1]=0;
	while(cur>=1) {
		#define add(p) ans1[cur]=p,x[cur--]=a[p--];
		if(p1==0) {add(p2); continue;}
		if(p2==mid) {add(p1); continue;}
		if(a[p1]==x[cur+1]) {add(p1); continue;}
		if(a[p2]==x[cur+1]) {add(p2); continue;}
		add(p1);
	}
	VI ans2;
	for(int i=1; i<=n; ++i) if(x[i]!=x[i+1]) ans2.PB(i);
	for(int i=1; i<=n; ++i)
		printf("%d%c", ans1[i], i<n?' ':'\n');
	printf("%d\n", (int)ans2.size());
	for(int i=0; i<(int)ans2.size(); ++i)
		printf("%d%c", ans2[i], i<(int)ans2.size()-1?' ':'\n');
	return 0;
}