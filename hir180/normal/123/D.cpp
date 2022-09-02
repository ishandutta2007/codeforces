#include <bits/stdc++.h>

using namespace std;

#define SIZE (1<<17)
typedef long long ll;

string S;

int sa[100005],lcp[100005],ran[100005],tmp[100005],k,n;

bool compare_sa(int i,int j)
{
	if(ran[i] != ran[j]) return ran[i] < ran[j];
	else
	{
		int ri = i+k < n?ran[i+k]:-1;
		int rj = j+k < n?ran[j+k]:-1;
		return ri < rj;
	}
}

void construct_sa()
{
	for(int i=0;i<=n;i++)
	{
		sa[i] = i;
		ran[i] = i<n?S[i]:-1;
	}
	for(k=1;k<=n;k*=2)
	{
		sort(sa,sa+n+1,compare_sa);
		
		tmp[sa[0]] = 0;
		
		for(int i=1;i<=n;i++)
		{
			tmp[sa[i]] = tmp[sa[i-1]] + compare_sa(sa[i-1],sa[i]);
		}
		for(int i=0;i<=n;i++)
		{
			ran[i] = tmp[i];
		}
	}
}

void construct_lcp()
{
	int h = 0;
	lcp[0] = 0;
	for(int i=0;i<n;i++)
	{
		int j = sa[ran[i]-1];
		
		if(h) h--;
		
		for(;j+h < n && i+h < n;h++)
		{
			if(S[j+h] != S[i+h]) break;
		}
		
		lcp[ran[i]-1] = h;
	}
}
ll seg[SIZE*2];
int le[SIZE*2],ri[SIZE*2],val[SIZE*2],cmp[SIZE*2];
bool all[SIZE*2];

void update(int k)
{
	if(all[k*2+1] && all[k*2+2])
	{
		le[k] = ri[k] = le[k*2+1]*2;
		all[k] = 1;
		seg[k] = seg[k*2+1] + seg[k*2+2] + 1LL*ri[k*2+1]*le[k*2+2];
		val[k] = val[k*2+1] + val[k*2+2];
		cmp[k] = 1;
	}
	else if(all[k*2+1])
	{
		all[k] = 0;
		le[k] = le[k*2+1] + le[k*2+2];
		ri[k] = ri[k*2+2];
		seg[k] = seg[k*2+1] + seg[k*2+2] + 1LL*ri[k*2+1]*le[k*2+2];
		val[k] = val[k*2+1] + val[k*2+2];
		cmp[k] = cmp[k*2+1] + cmp[k*2+2] - (ri[k*2+1] && le[k*2+2]);
	}
	else if(all[k*2+2])
	{
		all[k] = 0;
		le[k] = le[k*2+1];
		ri[k] = ri[k*2+1]+ri[k*2+2];
		seg[k] = seg[k*2+1] + seg[k*2+2] + 1LL*ri[k*2+1]*le[k*2+2];
		val[k] = val[k*2+1] + val[k*2+2];
		cmp[k] = cmp[k*2+1] + cmp[k*2+2] - (ri[k*2+1] && le[k*2+2]);
	}
	else
	{
		all[k] = 0;
		le[k] = le[k*2+1];
		ri[k] = ri[k*2+2];
		seg[k] = seg[k*2+1] + seg[k*2+2] + 1LL*ri[k*2+1]*le[k*2+2];
		val[k] = val[k*2+1] + val[k*2+2];
		cmp[k] = cmp[k*2+1] + cmp[k*2+2] - (ri[k*2+1] && le[k*2+2]);
	}
	if(ri[k*2+1] && le[k*2+2]) seg[k]--;

}

void add(int a,int k,int l,int r)
{
	if(l==r)
	{
		val[k] = cmp[k] = le[k] = ri[k] = all[k] = 1; seg[k] = 3;
		return;
	}
	if(l <= a && a <= (l+r)/2) add(a,k*2+1,l,(l+r)/2);
	else add(a,k*2+2,(l+r)/2+1,r);
	update(k);
}

void del(int a,int k,int l,int r)
{
	if(l==r)
	{
		val[k] = cmp[k] = seg[k] = le[k] = ri[k] = all[k] = 0;
		return;
	}
	if(l <= a && a <= (l+r)/2) del(a,k*2+1,l,(l+r)/2);
	else del(a,k*2+2,(l+r)/2+1,r);
	update(k);
}
vector<int>pos[100005];
int main()
{
	cin >> S; n = S.size();
	construct_sa();
	construct_lcp();
	for(int i=0;i<n;i++)
	{
		if(lcp[i]) add(i,0,0,SIZE-1);
		pos[lcp[i]].push_back(i);
	}
	ll res = 0;
	for(int i=1;i<=n;i++)
	{
		int exp = n-i+1;
		res += seg[0] + (exp-val[0]-cmp[0]);
		for(int j = 0;j < pos[i].size();j++)
		{
			del(pos[i][j],0,0,SIZE-1);
		}
	}
	
	cout << res << endl;
}