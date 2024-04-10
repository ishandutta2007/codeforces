#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool used[110];
vector <int> an;

struct Cut{
	int x1, y1, x2, y2;
	bool in(int x3, int y3, int x4, int y4){
		if (x1 == x2) return x3<=x1 && x1<=x4 && y1==y3 && y2==y4;
		return y3<=y1 && y1<=y4 && x1==x3 && x2==x4;
	}
	void scan(){scanf("%d%d%d%d", &x1, &y1, &x2, &y2);}
}cut[110];

void dfs(int x1, int y1, int x2, int y2, int n){
	for (int i = 0; i < n; i++){
		if (used[i]) continue;
		if (cut[i].in(x1, y1, x2, y2)){
			used[i] = 1;
			if (cut[i].x1 == cut[i].x2){
				dfs(x1, y1, cut[i].x1, y2, n), dfs(cut[i].x1, y1, x2, y2, n);
			}
			else dfs(x1, y1, x2, cut[i].y2, n), dfs(x1, cut[i].y1, x2, y2, n);
			return ;
		}
	}
	an.push_back((x2 - x1) * (y2 - y1));
}
main(){
	int W, H, n;
	scanf("%d%d%d", &W, &H, &n);
	for (int i = 0; i < n; i++){
		cut[i].scan();
	}
	dfs(0, 0, W, H, n);
	sort(an.begin(), an.end());
	for (int i = 0; i < an.size(); i++){
		printf("%d ", an[i]);
	}
	printf("\n");
}