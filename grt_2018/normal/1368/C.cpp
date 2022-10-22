#include <bits/stdc++.h>

using namespace std;

multiset<pair<int,int> >cells;

int dx[6] = {0,0,-1,1,1,-1};
int dy[6] = {-1,1,0,0,1,-1};


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		if(cells.find({i,i}) == cells.end())
		cells.insert({i,i});
		for(int j = 0; j < 6; ++j) {
			if(cells.find({i+dx[j],i+dy[j]}) == cells.end())
			cells.insert({i+dx[j],i+dy[j]});
		}
	}
	cout << cells.size() << "\n";
	for(auto it : cells) {
		cout << it.first << " " << it.second << "\n";
	}
}