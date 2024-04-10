#include<cstdio>
#include<vector>
#include<algorithm>
#define maxn 300000
struct node{
	int val, idx, idy;
	bool operator < (const node &rhs){
		return val == rhs.val ? idx < rhs.idx : val < rhs.val;
	}
};
std::vector<node> v;
int main(){
	int k;
	scanf("%d", &k);
	for(int i = 1; i <= k; i += 1){
		int sum = 0, n;
		scanf("%d", &n);
		std::vector<int> a(n);
		for(int j = 0; j < n; j += 1)
			scanf("%d", &a[j]), sum += a[j];
		for(int j = 0; j < n; j += 1)
			v.push_back((node){sum - a[j], i, j + 1});
	}
	std::sort(v.begin(), v.end());
	for(int i = 1; i < v.size(); i += 1)
		if(v[i].val == v[i - 1].val and v[i].idx != v[i - 1].idx)
			return printf("YES\n%d %d\n%d %d",
				v[i].idx, v[i].idy, v[i - 1].idx, v[i - 1].idy), 0;
	printf("NO");
}