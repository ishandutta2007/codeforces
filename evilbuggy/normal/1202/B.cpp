#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int minStep[10];
const int INF = 1e7;

void compute(int x, int y){
	for(int i = 0; i < 10; i++){
		minStep[i] = INF;
	}
	minStep[x] = 0;
	minStep[y] = 0;
	int vis[10] = {0};
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, x});
	pq.push({0, y});
	while(!pq.empty()){
		int v = pq.top().second;
		pq.pop();
		if(vis[v])continue;
		vis[v] = 1;
		if(minStep[(v+x)%10] > minStep[v] + 1){
			minStep[(v+x)%10] = minStep[v] + 1;
			pq.push({minStep[(v+x)%10], (v+x)%10});
		}
		if(minStep[(v+y)%10] > minStep[v] + 1){
			minStep[(v+y)%10] = minStep[v] + 1;
			pq.push({minStep[(v+y)%10], (v+y)%10});
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	if(s.size() == 1){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				cout<<0<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	int freq[10];
	memset(freq, 0, sizeof(freq));
	for(int i = 1; i < s.size(); i++){
		int val = s[i] - '0';
		val -= s[i - 1] - '0';
		val += 10;
		if(val >= 10)val -= 10;
		freq[val]++;
	}

	for(int x = 0; x < 10; x++){
		for(int y = 0; y < 10; y++){
			compute(x, y);
			// if(x == 4 && y == 3){
			// 	cout<<"HEY Sucker: ";
			// 	for(int i = 0; i < 10; i++){
			// 		cout<<minStep[i]<<" ";
			// 	}
			// 	cout<<endl<<endl;
			// }
			ll sum = 0;
			bool pos = true;
			for(int v = 0; v < 10; v++){
				if(!freq[v])continue;
				if(minStep[v] == INF){
					pos = false;
					break;
				}
				sum += minStep[v]*freq[v];
			}
			if(pos)cout<<sum<<" ";
			else cout<<-1<<" ";
		}
		cout<<endl;
	}

	return 0;
}