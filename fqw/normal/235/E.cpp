// 21:01
// 21:16 (sample)
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back

int p[9999], pn;
map<LL, unsigned> hash[9999];

unsigned dfs(int cur, int i, int j, int k) {
	if(cur==0) return 1;
	if(i>j) swap(i,j);
	if(i>k) swap(i,k);
	if(j>k) swap(j,k);
	LL key=(((cur*2222LL+i)*2222LL+j)*2222LL+k);
	map<LL, unsigned>::iterator it=hash[cur].find(key);
	if(it!=hash[cur].end())
		return it->second;
	unsigned ans=0;
	//ans+=dfs(cur-1, i,j,k);
	int x=p[cur];
	for(int a=i, ca=0; a>=1; a/=x,++ca)
	for(int b=j, cb=0; b>=1; b/=x,++cb)
	for(int c=k, cc=0; c>=1; c/=x,++cc)
		ans+=dfs(cur-1, a,b,c)*(unsigned)(ca+cb+cc+1);
	hash[cur].insert(MP(key, ans));
	return ans;
}

int main() {
	int a, b, c;
	scanf("%d%d%d", &a,&b,&c);
	pn=0;
	for(int i=2; i<=2000; ++i) {
		bool flag=true;
		for(int j=2; j*j<=i; ++j)
			if(i%j==0) flag=false;
		if(flag) p[++pn]=i;
	}
	unsigned ans=dfs(pn, a,b,c);
	ans=ans%(1<<30);
	cout<<ans<<endl;
	return 0;
}