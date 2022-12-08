#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 1e5+10;

struct obj
{
public:
	int x, i;
	bool operator < (obj o) const {return x<o.x;}
};
std::vector<obj> h[MN], v[MN], d1[MN*5], d2[MN*5];
int x[MN], y[MN], N, F[MN], M, cnt[MN];

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<M;++i)
	{
		scanf("%d%d", x+i, y+i);
		int a=x[i], b=y[i];
		h[a].push_back({b, i});
		v[b].push_back({a, i});
		d1[a-b+N].push_back({a, i});
		d2[a+b].push_back({a, i});
	}
	for(int i=0;i<=N;++i)
	{
		auto& k = h[i];
		std::sort(k.begin(), k.end());
		if(k.size()>1)
			for(int j=0;j<k.size();++j)
				cnt[k[j].i]+=2-((j==0)||(j+1==k.size()));
		auto& K = v[i];
		std::sort(K.begin(), K.end());
		if(K.size()>1)
			for(int j=0;j<K.size();++j)
				cnt[K[j].i]+=2-((j==0)||(j+1==K.size()));
	}
	for(int i=0;i<=N*3;++i)
	{
		auto& k = d1[i];
		std::sort(k.begin(), k.end());
		if(k.size()>1)
			for(int j=0;j<k.size();++j)
				cnt[k[j].i]+=2-((j==0)||(j+1==k.size()));
		auto& K = d2[i];
		std::sort(K.begin(), K.end());
		if(K.size()>1)
			for(int j=0;j<K.size();++j)
				cnt[K[j].i]+=2-((j==0)||(j+1==K.size()));
	}
	for(int i=0;i<M;++i)
		F[cnt[i]]++;
	for(int i=0;i<=8;++i)
		printf("%d ", F[i]);
	return 0;
}