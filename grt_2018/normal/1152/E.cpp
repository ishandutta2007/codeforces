#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 200*1000+1;
int n,nr;
pii e[nax];
map<int,int>sc;
vector<pii>V[nax];
bool visited[nax];
int inv[nax],I[nax];
int cnt_odd,start;
vi euler;

void dfs(int x) {
	while(I[x]<(int)V[x].size()) {
		pii tmp = V[x][I[x]];
		if(!visited[tmp.ND]) {
			visited[tmp.ND]=1;
			dfs(tmp.ST);
		}
		I[x]++;
	}
	euler.PB(x);
}


int main() {
	scanf("%d",&n);
	for(int i=0; i<n-1;i++) {
		scanf("%d",&e[i].ST);
		sc[e[i].ST];
	}
	for(int i=0; i<n-1;i++) {
		scanf("%d",&e[i].ND);
		if(e[i].ST>e[i].ND) {
			printf("-1");
			return 0;
		}
		sc[e[i].ND];
	}
	for(auto &it:sc) {
		inv[nr] = it.ST;
		it.ND = nr++;
	}
	for(int i=0; i<n-1;i++) {
		e[i].ST = sc[e[i].ST];
		e[i].ND = sc[e[i].ND];
		V[e[i].ST].emplace_back(e[i].ND,i);
		V[e[i].ND].emplace_back(e[i].ST,i);
	}
	for(int i=0; i<nr;i++) {
		if(((int)V[i].size())%2==1) {
			cnt_odd++;
			start = i;
		}
	}
	//for(int i=0; i<nr;i++) {
	//	printf("%d : ",i);
	//	for(auto it:V[i]) printf("(%d %d) ",it.ST,it.ND);
	//	printf("\n");
	//}
	if(cnt_odd>2) {
		printf("-1");
		return 0;
	}
	dfs(start);
	if((int)euler.size()!=n) {
		printf("-1");
		return 0;
	}
	for(auto it:euler) printf("%d ",inv[it]);
}