#include <bits/stdc++.h>

using namespace std;

int jump[100005][20][2];
int n;
int a[100005];

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	for(int j=0; j < 19; ++j){
		jump[n][j][0]=n+1;
		jump[n][j][1]=n+1;
	}
	for(int i=n-1; i >= 0; --i){
		jump[i][0][0]=jump[i+1][0][0];
		jump[i][0][1]=jump[i+1][0][1];
		jump[i][0][a[i]-1]=i+1;
	}
	for(int k=0; k < 2; ++k)
	for(int j=0; j < 19; ++j)
		for(int i=0; i < n; ++i){
			if(jump[i][j][k] == n+1)
				jump[i][j+1][k]=n+1;
			else
				jump[i][j+1][k]=jump[jump[i][j][k]][j][k];
		}
	vector<pair<int, int> > ans;
	for(int s=1; s <= n; ++s){
		int pos=0;
		int t[2]={0,0};
		while(true){
		int np[2]={pos,pos};
		for(int k=0; k < 2; ++k){
			for(int i=0; i < 19; ++i){
				if(s&(1<<i)){
					np[k]=jump[np[k]][i][k];
					if(np[k] == n+1)
						break;
				}
			}
		}
		if(np[0] == n+1 && np[1] == n+1)
			break;
		int win=(np[0]<np[1]?0:1);
		pos=min(np[0], np[1]);
		++t[win];
		if(pos == n && t[win] > t[1-win]){
			ans.push_back(make_pair(t[win], s));
			break;
		}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i=0; i < ans.size(); ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
}