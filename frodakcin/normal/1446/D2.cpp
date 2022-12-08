#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 2e5+10;
const int INF = 0x3f3f3f3f;

int N, M, a[MN], c[MN], v, x[MN], ans, _pr[MN*2], *pr=_pr+MN;
std::vector<int> loc[MN];

int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;++i)
		scanf("%d", a+i), ++c[a[i]];

	{
		int b=-1;
		for(int i=1;i<=N;++i)
			if(b<c[i])
				b=c[i], v=i;
			else if(b==c[i]) v=-1;
		assert(v);
		if(!~v) return printf("%d\n", N), 0;
	}

	x[M++]=0;
	for(int i=1;i<=N;++i)
		if(a[i]==v)
			x[M++]=i;
		else
			loc[a[i]].push_back(M);
	x[M++]=N+1;

	memset(_pr, -1, sizeof _pr);
	for(int i=1;i<=N;++i)
	{
		if(i==v) continue;
		std::vector<int> &a=loc[i];
		if(a.empty()) continue;
		int L=a.size()+1, z=0;
		std::vector<int> key;
		for(int v:a)
			for(ckmax(z, v-L);z<M && z<v+L;++z)
				key.push_back(z);
		int max=-INF, min=INF, cur=0;
		for(int j=0, k=0;j<key.size();++j, --cur)
		{
			for(;k<a.size() && a[k]==key[j];++k) ++cur;
			ckmax(max, cur);
			ckmin(min, cur);
			if(~pr[cur+1] && j>pr[cur+1]+1) ckmax(ans, x[key[j]]-x[key[pr[cur+1]]]-1);
			if(!~pr[cur]) pr[cur]=j;
			//(i, j) : (j-i-1) == p[j]-p[i] ~~ p[i]-i == 1+p[j]-j ~~ ans = x[key[j]]-x[key[i]]-1
		}
		memset(pr+min, -1, (max-min+1)*sizeof*pr);
	}

	printf("%d\n", ans);
	return 0;
}