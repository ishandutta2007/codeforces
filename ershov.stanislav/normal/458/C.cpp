#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

const int maxn=111111;

int n, a[maxn], b[maxn], cor[maxn], mx[maxn], cnt, cnt2, cur;
int res, ans=2000000000;
bool blocked[maxn], used[maxn];
vector<int> cands[maxn];
vector<int> people[maxn];
vector<int> lst;
vector<int> a1[maxn], a2;
vector<pair<int, int> > lst2;

int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		cands[a[i]].push_back(b[i]);
	}
	for (int i=0; i<maxn; i++) sort(cands[i].begin(), cands[i].end(), greater<int> ());
	for (int i=0; i<maxn; i++) for (int j=0; j<cands[i].size(); j++) people[j].push_back(cands[i][j]), a1[j].push_back(i);
	int k=0;
	for (int i=0; i<maxn; i++) for (int j=0; j<people[i].size(); j++, k++) lst.push_back(people[i][j]), a2.push_back(a1[i][j]), lst2.push_back(make_pair(people[i][j], k)),
		mx[k]=i+1;
	sort(lst2.begin(), lst2.end());
	for (int i=0; i<lst2.size(); i++) cor[lst2[i].second]=i;
	for (int i=0; i<lst2.size()&&i<(a2[lst2.size()-1]?mx[lst2.size()-1]:mx[lst2.size()-2])+1; i++) used[i]=true, res+=lst2[i].first, cnt2++, cur=i;
	ans=res;
	for (int i=(int)lst.size()-1; i>=1; i--) if (a2[i]) {
		blocked[cor[i]]=true;
		cnt++;
		if (!used[cor[i]]) res+=lst[i];
		else cnt2--;
		while (cur>=0&&cnt2>(a2[i-1]?mx[i-1]:mx[i-2])+1-cnt) {
			if (blocked[cur]) cur--;
			else res-=lst2[cur].first, used[cur]=false, cur--, cnt2--;
		}
		ans=min(ans, res);
	}
	printf("%d", ans);
	return 0;
}