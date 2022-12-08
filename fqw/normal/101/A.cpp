#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=100010;

char s[MAXN], t[MAXN];
int n, k;

int main() {
	scanf("%s%d", s+1, &k); n=strlen(s+1);
	int cnt[26]={0};
	for(int i=1; i<=n; ++i) cnt[s[i]-'a']++;
	vector<pair<int,char> > lst;
	for(int i=0; i<26; ++i) lst.push_back(make_pair(cnt[i],'a'+i));
	sort(lst.begin(), lst.end());
	int cur=0;
	while(cur<26 && k>=lst[cur].first) {
		k-=lst[cur].first;
		cnt[lst[cur].second-'a']=-1;
		++cur;
	}
	printf("%d\n", 26-cur);
	for(int i=1; i<=n; ++i) if(cnt[s[i]-'a']>=0) printf("%c", s[i]);
	printf("\n");

	return 0;
}