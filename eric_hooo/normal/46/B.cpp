#include <bits/stdc++.h>
using namespace std;

int sum[5];
char buf[10];
map <string, int> mp;
string type[5] = {"S", "M", "L", "XL", "XXL"};

string read(){
	scanf("%s", buf);
	return buf;
}

int main(){
	mp["S"] = 0, mp["M"] = 1, mp["L"] = 2, mp["XL"] = 3, mp["XXL"] = 4;
	for (int i = 0; i < 5; i++){
		scanf("%d", &sum[i]);
	}
	int k; scanf("%d", &k);
	while (k--){
		string s = read();
		int id = mp[s], l = id, r = id;
		while (1){
			if (sum[r]){
				sum[r]--, printf("%s\n", type[r].c_str());
				break;
			}
			if (sum[l]){
				sum[l]--, printf("%s\n", type[l].c_str());
				break;
			}
			if (l != 0) l--;
			if (r != 4) r++;
		}
	}
	return 0;
}