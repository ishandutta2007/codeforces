#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

const int maxn=100111;

struct task {
	int i, j, k;
};

inline bool compare (task a, task b) { return a.i>b.i; }

int n, a[maxn], m, sum[maxn], pr[maxn], parent[maxn], ans[maxn], start2[maxn];
vector<int> start[maxn];
task tasks[maxn];

int getpar(int v) {
	if (parent[v]==v) return v;
	else return parent[v]=getpar(parent[v]);
}

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]), sum[i+1]=sum[i]+a[i], parent[i]=i;
	scanf("%d", &m);
	for (int i=0; i<m; i++) scanf("%d%d", &tasks[i].i, &tasks[i].j), tasks[i].i=tasks[i].j-tasks[i].i, tasks[i].j-=1, tasks[i].k=i;
	stack<pair<int, int> > st;
	st.push(make_pair(-1, -1));
	for (int i=0; i<n; i++) start2[i]=maxn;
	for (int i=0; i<n; i++) {
		while (st.size()&&st.top().first>=a[i]) {
			st.pop();
		}
		pr[i]=st.top().second;
		
		if (pr[i]!=-1) {
			int k=0;
			while (true) {
				k=(sum[i+1]-sum[pr[i]+1]-a[pr[i]]*(i-pr[i]))/(a[i]-a[pr[i]]);
				if ((sum[i+1]-sum[pr[i]+1]-a[pr[i]]*(i-pr[i]))%(a[i]-a[pr[i]])) k++;
				k=min(max(k, i-pr[i]+1), maxn);
				if (k-(i-pr[i])>=start2[pr[i]]) {
					st.pop();
					pr[i]=st.top().second;
				} else break;
			}
			if (k<i+2) start[i-k+1].push_back(i), start2[i]=k;
		}
		st.push(make_pair(a[i], i));
	}
	sort(tasks, tasks+m, compare);
	for (int cur=n-1, i=0; i<m; i++) {
		while (cur>tasks[i].i) {
			cur--;
			for (int j=0; j<start[cur].size(); j++) if (parent[start[cur][j]]==start[cur][j]) {
				parent[start[cur][j]]=getpar(pr[start[cur][j]]);
			}
		}
		int aa=getpar(tasks[i].j), bb=tasks[i].j;
		ans[tasks[i].k]=sum[bb+1]-sum[aa+1]+a[aa]*(tasks[i].j-tasks[i].i+1-bb+aa);
	}
	for (int i=0; i<m; i++) printf("%d\n", ans[i]);
	return 0;
}