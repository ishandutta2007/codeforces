#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int a[505][505];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin>>a[i][j];
		}
	}
	vector<int> ans;
	for(int mask = 1; mask < 1024; mask <<= 1){
		int cnt[3] = {0};
		for(int i = 1; i <= n; i++){
			int tmp[2] = {0};
			for(int j = 1; j <= m; j++){
				if(a[i][j]&mask)tmp[1]++;
				else tmp[0]++;
			}
			if(!tmp[1])cnt[0]++;
			else if(!tmp[0])cnt[1]++;
			else cnt[2]++;
		}
		if(cnt[1]&1){
			for(int i = 1; i <= n; i++){
				int tmp[2] = {0};
				for(int j = 1; j <= m; j++){
					if(a[i][j]&mask)tmp[1]++;
					else tmp[0]++;
				}
				if(!tmp[1] || !tmp[0])ans.push_back(1);
				else{
					for(int j = 1; j <= m; j++){
						if(a[i][j]&mask)continue;
						ans.push_back(j);
						break;
					}
				}
			}
			break;
		}else if(cnt[2] > 0){
			bool used = false;
			for(int i = 1; i <= n; i++){
				int tmp[2] = {0};
				for(int j = 1; j <= m; j++){
					if(a[i][j]&mask)tmp[1]++;
					else tmp[0]++;
				}
				if(!tmp[1] || !tmp[0])ans.push_back(1);
				else{
					if(used){
						for(int j = 1; j <= m; j++){
							if(a[i][j]&mask)continue;
							ans.push_back(j);
							break;
						}
					}else{
						for(int j = 1; j <= m; j++){
							if(a[i][j]&mask){
								ans.push_back(j);
								break;
							}
						}
						used = true;
					}
				}
			}
			break;
		}
	}

	if(ans.empty())cout<<"NIE"<<endl;
	else{
		cout<<"TAK"<<endl;
		for(auto x : ans){
			cout<<x<<" ";
		}
	}

	return 0;
}