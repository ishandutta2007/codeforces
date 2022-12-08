#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e5 + 100;

int N, Q;
struct STN
{
	int v, w, l, r, a;
	int z;
	STN operator + (const STN& o) const
	{
		STN k;
		k.v = max(v, o.v);
		k.w = min(w, o.w);
		k.l = max(v-(o.w<<1), max(l, o.l));
		k.r = max(o.v-(w<<1), max(r, o.r));
		k.a = max(max(a, o.a), max(l+o.v, v+o.r));
		k.z = 0;
		return k;
	}
	void upd(int k)
	{
		z += k;
		v += k, w += k;
		l -= k, r -= k;
	}
};
STN t[MN<<3];
int p[MN<<1];
char c;
void init(int n, int l, int r)
{
	if(r-l>1)
	{
		int m = l + (r-l>>1);
		init(n<<1, l, m), init(n<<1|1, m, r);
		t[n] = t[n<<1] + t[n<<1|1];
	}
	else
		t[n].v=t[n].w=p[l+1], t[n].l=t[n].r=-p[l+1], t[n].a=0;
}
void down(int n, int l, int r)
{
	if(!t[n].z) return;
	if(r-l>1)
		t[n<<1].upd(t[n].z), t[n<<1|1].upd(t[n].z);
	t[n].z = 0;
}
void upd(int n, int l, int r, int ql, int qr, int x)
{
	if(ql<=l&&r<=qr)
		t[n].upd(x);
	else
	{
		down(n, l, r);
		int m = l + (r-l>>1);
		if(ql<m) upd(n<<1, l, m, ql, qr, x);
		if(m<qr) upd(n<<1|1, m, r, ql, qr, x);
		t[n] = t[n<<1]+t[n<<1|1];
	}
}
char s[MN<<1];
int main(void)
{
	scanf("%d%d", &N, &Q);
	scanf(" %s", s);
	for(int i = 0;i < N-1<<1;i++)
		p[i+1] = p[i]+(s[i]=='('?1:-1);
	init(1, 0, N-1<<1);
	printf("%d\n", t[1].a);
	for(int a, b;Q--;)
	{
		scanf("%d%d", &a, &b), a--, b--;
		if(b<a)swap(a,b);
		swap(s[a], s[b]);
		upd(1, 0, N-1<<1, a, b, s[a]=='('?2:-2);
		printf("%d\n", t[1].a);
	}
	return 0;
}