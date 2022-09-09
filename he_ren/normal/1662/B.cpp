#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int read(int a[])
{
	static char s[MAXN];
	scanf("%s",s+1);
	for(int i=1; s[i]; ++i)
		++a[s[i] - 'A'];
	return strlen(s+1);
}


int a[30], b[30], c[30];

int main(void)
{
	int lena = read(a), lenb = read(b), lenc = read(c);
	
	int lim = min({lena, lenb, lenc});
	
	vector<pii> ans;
	vector<int> ta, tb, tc;
	int tot = 0;
	for(int i=0; i<26; ++i)
	{
		int x = 0, y = 0, z = 0, cur = 0;
		for(int xx=0; xx<=b[i] && xx<=a[i]; ++xx)
			for(int yy=0; xx+yy<=b[i] && yy<=c[i] && tot+xx+yy<=lim; ++yy)
			{
				int zz = min(a[i] - xx, c[i] - yy);
				zz = min(zz, lim - xx - yy - tot);
				if(xx + yy + zz > cur)
				{
					x = xx; y = yy; z = zz;
					cur = xx + yy + zz;
				}
			}
		tot += cur;
		assert(tot <= lim);
		
		tc.insert(tc.end(), x, i); a[i] -= x; b[i] -= x;
		ta.insert(ta.end(), y, i); c[i] -= y; b[i] -= y;
		tb.insert(tb.end(), z, i); a[i] -= z; c[i] -= z;
		
//		if(x || y || z)
//			printf("%c: x = %d, y = %d, z = %d\n",i + 'A',x,y,z);
	}
	
	vector<int> va, vb, vc;
	for(int i=0; i<26; ++i)
	{
		va.insert(va.end(), a[i], i);
		vb.insert(vb.end(), b[i], i);
		vc.insert(vc.end(), c[i], i);
	}
	
	assert(va.size() >= ta.size());
	assert(vb.size() >= tb.size());
	assert(vc.size() >= tc.size());
	
	auto upd = [&] (vector<int> &A,vector<int> &B)
	{
		ans.emplace_back(A.back(), B.back());
		A.pop_back(); B.pop_back();
	};
	
	while(ta.size()) upd(ta, va);
	while(tb.size()) upd(tb, vb);
	while(tc.size()) upd(tc, vc);
	
	while(va.size() && (vb.size() || vc.size()))
	{
		if(vb.size() > vc.size())
			upd(va, vb);
		else
			upd(va, vc);
	}
	while(vb.size() && vc.size())
		upd(vb, vc);
	
	for(int x: va) ans.emplace_back(x, 0);
	for(int x: vb) ans.emplace_back(x, 0);
	for(int x: vc) ans.emplace_back(x, 0);
	
	printf("%d\n",(int)ans.size());
	for(pii t: ans)
	{
		putchar(t.first + 'A');
		putchar(t.second + 'A');
		putchar('\n');
	}
	return 0;
}