#include <bits/stdc++.h>

using namespace std;

map<pair<string, int>, int> bad;

int main(){
	int n;
	string name1, name2;
	cin >> name1 >> name2;
	cin >> n;
	for(int i=0; i < n; ++i){
		int t;
		string h;
		int num;
		string type;
		cin >> t >> h >> num >> type;
		pair<string, int> p=make_pair(h, num);
		if(bad[p] >= 2)
			continue;
		if(type == "y")
			++bad[p];
		else
			bad[p] += 2;
		if(bad[p] >= 2){
			if(h == "h")
				cout << name1;
			else
				cout << name2;
			cout << " " << num << " " << t << endl;
		}
	}
}