#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int read() {
	int x=0;
	char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) x=x*10+c-'0', c=getchar();
	return x;
}
const int N=300005;
struct edge {
	int l, r, w;
} e[N];
int Min[N*16], T[N*16];
bool cmp(edge a, edge b) {
	return a.w<b.w;
}
void add(int x, int l, int r, int L, int R, int v) {
	if (L<=l&&r<=R) {
		T[x]+=v;
		Min[x]+=v;
		return ;
	}
	int mid=(l+r)/2;
	if (T[x]) {
		T[2*x]+=T[x];
		T[2*x+1]+=T[x];
		Min[2*x]+=T[x];
		Min[2*x+1]+=T[x];
		T[x]=0;
	}
	if (L<=mid) add(2*x, l, mid, L, R, v);
	if (mid<R) add(2*x+1, mid+1, r, L, R, v);
	Min[x]=min(Min[x*2], Min[x*2+1]);
}
vector<int> v;
int main()
{	
	int n=read(), m=read();
	for (int i=1; i<=n; i++) {	
		e[i].l=read(), e[i].r=read(), e[i].w=read();
		v.push_back(e[i].l); v.push_back(e[i].r);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i=1; i<=n; i++) {
		e[i].l=lower_bound(v.begin(), v.end(), e[i].l)-v.begin()+1;
		e[i].r=lower_bound(v.begin(), v.end(), e[i].r)-v.begin()+1;
	}
	m=v.size();
	sort(e+1, e+1+n, cmp);
	int ans=2e9;
	for (int i=1, j=0; i<=n; i++) {
		while (j+1<=n&&!Min[1]) {
			++j; 
			add(1, 1, m-1, e[j].l, e[j].r-1, 1);
		}
		if (Min[1]) {	
			ans=min(ans, e[j].w-e[i].w);
			add(1, 1, m-1, e[i].l, e[i].r-1, -1);
		}
		else break;
	}
	cout<<ans;
	return 0;
}