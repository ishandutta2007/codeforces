#include <bits/stdc++.h>
using namespace std;

const int N = 7005;
int n, a, b, x[N], y[N], deg[N][2], dist[N][2], ans[N][2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cin >> a;
	for(int i = 0; i < a; i++){
		cin >> x[i];
	}
	cin >> b;
	for(int i = 0; i < b; i++){
		cin >> y[i];
	}
	for(int i = 0; i < n; i++){
		deg[i][0] = a;
		deg[i][1] = b;
	}
	memset(ans, -1, sizeof(ans));
	queue<int> qp, qi;
	qi.push(0); qp.push(0);
	qi.push(0); qp.push(1);
	ans[0][0] = 0;
	ans[0][1] = 0;
	while(!qi.empty()){
		int cur = qi.front(); qi.pop();
		int pla = qp.front(); qp.pop();
		if(pla == 0){
			for(int i = 0; i < b; i++){
				int st = cur - y[i]; if(st < 0)st += n;
				if(ans[st][1] != -1)continue;
				if(ans[cur][0] == 0){
					ans[st][1] = 1;
					qi.push(st); qp.push(1);
				}else{
					deg[st][1]--;
					if(deg[st][1] == 0){
						ans[st][1] = 0;
						qi.push(st); qp.push(1);
					}
				}
			}
		}else{
			for(int i = 0; i < a; i++){
				int st = cur - x[i]; if(st < 0)st += n;
				if(ans[st][0] != -1)continue;
				if(ans[cur][1] == 0){
					ans[st][0] = 1;
					qi.push(st); qp.push(0);
				}else{
					deg[st][0]--;
					if(deg[st][0] == 0){
						ans[st][0] = 0;
						qi.push(st); qp.push(0);
					}
				}
			}
		}
	}
	for(int i = 1; i < n; i++){
		if(ans[i][0] == 0){
			cout << "Lose ";
		}else if(ans[i][0] == 1){
			cout << "Win ";
		}else{
			cout << "Loop ";
		}
	}
	cout << '\n';
	for(int i = 1; i < n; i++){
		if(ans[i][1] == 0){
			cout << "Lose ";
		}else if(ans[i][1] == 1){
			cout << "Win ";
		}else{
			cout << "Loop ";
		}
	}
	cout << '\n';

	return 0;
}