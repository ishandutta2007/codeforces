#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>S[N],id[2],Id[2][2];
char s[N];
void Swap() {
	if(!Id[1][0].empty()||!Id[1][1].empty())return;
	if(Id[0][0].empty()||Id[0][1].empty())return;
	int a=Id[0][0].back(),b=Id[0][1].back();
	if(S[a].back()>S[b].back())swap(a,b);
	S[a].push_back(S[b].back());
	S[b].pop_back();
	Id[1][0].push_back(Id[0][1].back());
	Id[1][1].push_back(Id[0][0].back());
	Id[0][0].pop_back();
	Id[0][1].pop_back();
}
void print(int x) {
	for(int i:S[x])
		printf("%d ",i);
}
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1),tot=0;
	for(int i=1;i<=n;i++) {
		int c=s[i]=='R';
		if(id[c^1].empty())id[c^1].push_back(++tot);
		S[id[c^1].back()].push_back(i);
		id[c].push_back(id[c^1].back());
		id[c^1].pop_back();
	}
	printf("%d\n",tot-1);
	for(int i=1;i<=tot;i++)
		Id[S[i].size()&1][s[S[i].back()]=='R'].push_back(i);
	Swap();
	int t=Id[1][1].size()>Id[1][0].size();
	if(Id[1][t].empty())t=Id[0][1].size()<Id[0][0].size();
	while(!Id[0][t^1].empty())print(Id[0][t^1].back()),Id[0][t^1].pop_back();
	while(!Id[1][t].empty()) {
		print(Id[1][t].back());
		Id[1][t].pop_back();
		while(!Id[0][t].empty())print(Id[0][t].back()),Id[0][t].pop_back();
		t^=1;
	}
	return 0;
}