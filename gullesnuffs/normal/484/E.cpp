#include <bits/stdc++.h>
#define MAXW 700
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int n, m;
int h[200005];
int jump[140005][20];
vector<int> ans[2][20];
set<int> S;
vector<int> v;
vector<pair<pii, pii> > queries;
int ansSaved[100005];

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", h+i);
		S.insert(h[i]);
		jump[i][0]=h[i];
	}
	trav(it,S){
		v.push_back(*it);
	}
	for(int i=0; i < 19; ++i)
		for(int j=0; j+(2<<i) <= n+1; ++j){
			jump[j][i+1]=min(jump[j][i],jump[j+(1<<i)][i]);
		}
	/*for(int w=1; w < MAXW; ++w)
		for(int i=0; i < 20; ++i)
			ans[w][i]=vector<int>(n/(1<<i));*/
	/*for(int i=0; i < n; ++i){
		int Min=1000000005;
		for(int w=1; w < MAXW && i+w <= n; ++w){
		
			Min=min(Min, h[i+w-1]);
			ans[w][0][i]=Min;
		}
	}*/
	/*for(int w=1; w < MAXW; ++w)
		for(int i=0; i < 19; ++i)
			for(int j=0; j+(2<<i) <= n; j += (2<<i)){
				ans[w][i+1][j/(2<<i)]=max(ans[w][i][j/(1<<(i))],ans[w][i][j/(1<<(i))+1]);
			}*/
	scanf("%d", &m);
	for(int i=0; i < m; ++i){
		int l,r,w;
		scanf("%d%d%d", &l, &r, &w);
		queries.push_back(make_pair(make_pair(w,i),make_pair(l,r)));
	}
	sort(all(queries));
	int curW=0;
	bool read=0;
	bool write=1;
	for(int q=0; q < m; ++q){
		int l=queries[q].second.first;
		int r=queries[q].second.second;
		int w=queries[q].first.first;
		if(w < MAXW-1){
			while(curW < w){
				++curW;
				write^=1;
				read^=1;
				for(int i=0; i < 20; ++i)
					ans[write][i]=vector<int>(n/(1<<i));
				for(int i=0; i < n; ++i){
					if(curW == 1)
						ans[write][0][i]=h[i+curW-1];
					else
						ans[write][0][i]=min(ans[read][0][i], h[i+curW-1]);
				}
				for(int i=0; i < 19; ++i)
					for(int j=0; j+(2<<i) <= n; j += (2<<i)){
						ans[write][i+1][j/(2<<i)]=max(ans[write][i][j/(1<<(i))],ans[write][i][j/(1<<(i))+1]);
					}

				for(int i=0; i < 20; ++i){
					ans[read][i].clear();
				}
			}
			int A=0;
			for(int i=0; i <= 19; ++i){
				if(l+(1<<i)+w <= r+2 && ((l-1)&(1<<i))){
					A=max(A,ans[write][i][(l-1)/(1<<i)]);
					l += (1<<i);
				}
			}
			for(int i=19; i >= 0; --i){
				if(l+(1<<i)+w <= r+2){
					A=max(A,ans[write][i][(l-1)/(1<<i)]);
					l += (1<<i);
				}
			}
			ansSaved[queries[q].first.second]=A;
			//printf("%d\n", A);
		}
		else{
			int A=0;
			int Min=0;
			int Max=v.size();
			int minPow=0;
			int minPos=l-1;
			for(;(1<<minPow)<=w; ++minPow);
			while(Max-Min > 1){
				int midind=(50*Min+Max)/51;
				if(midind == Min)
					++midind;
				int mid=v[midind];
				int lef=minPos;
				int pos=minPos;
				int p=minPow;
				bool ok=0;
				while(lef+w <= r){
					/*if(pos+(1<<p) > r+1){
						--p;
						continue;
					}*/
					while(pos+(1<<p)-lef > w){
						--p;
						continue;
					}
					/*if(pos&((1<<p)-1)){
						--p;
						continue;
					}*/
					if(jump[pos][p] < mid){
						if(p == 0){
							lef=pos+1;
							++pos;
							//while(!(pos&((2<<p)-1)))
							//	++p;
							p=minPow;
							continue;
						}
						if(jump[pos+(1<<(p-1))][p-1] < mid){
							lef=pos+(1<<(p-1));
							pos=lef;
						}
						--p;
						for(; p > 0; --p){
							if(jump[pos+(1<<(p-1))][p-1] < mid){
								pos += (1<<(p-1));
							}
						}
						if(jump[pos][0] < mid)
							++pos;
						lef=pos;
						p=minPow;
						continue;
					}
					pos += (1<<p);
					if(pos-lef >= w){
						ok=1;
						minPos=lef;
						break;
					}
					//while(!(pos&((2<<p)-1)))
					//	++p;
					--p;
				}
				if(ok)
					Min=midind;
				else
					Max=midind;
			}
			ansSaved[queries[q].first.second]=v[Min];
			//printf("%d\n", v[Min]);
		}
	}
	for(int i=0; i < m; ++i)
		printf("%d\n", ansSaved[i]);
}