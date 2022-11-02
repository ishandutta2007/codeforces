#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long LL;
const int maxN = 100000 + 233;//1e5
int n;
LL ans = 0;
struct Node {
	int s, h;
	Node(int s=0, int h=0) : s(s), h(h) {}
}node[maxN];
char s[maxN];
int p[maxN];
bool cmp(int x, int y) {
	return node[x].s * (LL)node[y].h > node[y].s * (LL)node[x].h;
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		p[i] = i;
		scanf("%s", s);
		int len = strlen(s);
		int cs = 0, ch = 0;
		for(int j=0; j<len; j++) {
			if(s[j] == 's') cs++;
			else ans += cs, ch++;
		}
		node[i] = Node(cs, ch);
	}
	std::sort(p, p+n, cmp);
	LL ss = node[p[0]].s;
	for(int i=1; i<n; i++) {
		ans += ss * node[p[i]].h;
		ss += node[p[i]].s;
	}
	printf("%lld\n", ans);
	return 0;
}