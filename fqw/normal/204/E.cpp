#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=100010*2;
const int MAXLogN=20;

int sa[MAXN], rank[MAXN], height[MAXN], limit[MAXN];
int bbc[MAXN], wxa[MAXN], wxb[MAXN];
char str[MAXN];
int len;
void cal_sa() {
	int *x=wxa, *y=wxb, size=256;
	memset(bbc, 0, sizeof(bbc));
	for(int i=1; i<=len; ++i) ++bbc[x[i]=(int)str[i]];
	for(int i=1; i<=size; ++i) bbc[i]+=bbc[i-1];
	for(int i=len; i>=1; --i) sa[bbc[x[i]]--]=i;
	for(int w=1; w<len; w*=2, size=len) {
		int p=0;
		for(int i=len-w+1; i<=len; ++i) y[++p]=i;
		for(int i=1; i<=len; ++i) if(sa[i]>w) y[++p]=sa[i]-w;
		memset(bbc, 0, sizeof(bbc));
		for(int i=1; i<=len; ++i) ++bbc[x[i]];
		for(int i=1; i<=size; ++i) bbc[i]+=bbc[i-1];
		for(int i=len; i>=1; --i) sa[bbc[x[y[i]]]--]=y[i];
		swap(x, y); x[sa[1]]=1;
		for(int i=2; i<=len; ++i) {
			int j=sa[i], k=sa[i-1];
			x[j]=x[k]+(y[k]<y[j]||y[k+w]<y[j+w]);
		}
	}
}
void cal_height() {
	for(int i=1; i<=len; ++i) rank[sa[i]]=i;
	for(int i=1, j, h=0; i<=len; height[rank[i++]]=h)
		for(h?h--:0, j=sa[rank[i]-1]; str[i+h]==str[j+h]; ++h);
}

vector<int> t_in[MAXN], t_out[MAXN];

long long ans[MAXN];
int belong[MAXN];
int hash[MAXN];
char buf[MAXN];
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	len=0;
	for(int i=1; i<=n; ++i) {
		scanf("%s", buf);
		int curlen=strlen(buf);
		for(int j=0; j<curlen; ++j) {
			str[++len]=buf[j];
			belong[len]=i;
			limit[len]=curlen-j;
		}
		str[++len]='$';
		belong[len]=0;
	}
	cal_sa();
	cal_height();

	int cnt; multiset<int> basket;
	for(int i=1; i<=len; ++i) t_in[i].clear(), t_out[i].clear();

	memset(hash, 0, sizeof(hash));
	cnt=0; hash[0]=1;
	basket.clear();
	for(int i=1, j=0; i<=len; ++i) {
		while(cnt<k) {
			if(++j>len) break;
			if(hash[belong[sa[j]]]++==0)
				++cnt;
			basket.insert(height[j]);
			basket.insert(limit[sa[j]]);
		}
		if(j>len) break;
		basket.erase(basket.find(height[i]));
		int p=*basket.begin();
		t_in[i].push_back(p); t_out[j].push_back(p);
		basket.erase(basket.find(limit[sa[i]]));
		if(--hash[belong[sa[i]]]==0)
			--cnt;
	}
	memset(hash, 0, sizeof(hash));
	cnt=0; hash[0]=1;
	basket.clear();
	for(int j=len, i=len+1; j>=1; --j) {
		while(cnt<k) {
			if(--i<1) break;
			if(hash[belong[sa[i]]]++==0)
				++cnt;
			basket.insert(height[i+1]);
			basket.insert(limit[sa[i]]);
		}
		if(i<1) break;
		basket.erase(basket.find(height[j+1]));
		int p=*basket.begin();
		t_in[i].push_back(p); t_out[j].push_back(p);
		basket.erase(basket.find(limit[sa[j]]));
		if(--hash[belong[sa[j]]]==0)
			--cnt;
	}

	memset(ans, 0, sizeof(ans));
	basket.clear();
	for(int i=1; i<=len; ++i) {
		for(int k=0; k<t_in[i].size(); ++k) basket.insert(-t_in[i][k]);
		if(belong[sa[i]]>0 && basket.size()>0)
			ans[belong[sa[i]]]+=-*(basket.begin());
		for(int k=0; k<t_out[i].size(); ++k) basket.erase(basket.find(-t_out[i][k]));
	}
	for(int i=1; i<=n; ++i)
		printf("%I64d%c", ans[i], i<n?' ':'\n');
	return 0;
}