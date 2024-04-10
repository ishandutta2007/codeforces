#include <bits/stdc++.h>
using namespace std;

char buf[100010];
long long cnt[30];
vector <int> all[30];
string s;

string find(int now, int k, vector <int> Pos){
//	cout << now << " " << k << " " << Pos.size() << endl;
//	if (k < 0) return "";
	if (k <= Pos.size() && now != 0) return "";
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i <= 26; i++){
		all[i].clear();
	}
	cnt[0] = now ? Pos.size() : 0;
	for (int i = 0; i < Pos.size(); i++){
		int pos = Pos[i];
		if (pos >= s.length()) continue;
		cnt[s[pos] - 'a' + 1] += s.length() - pos;
		all[s[pos] - 'a' + 1].push_back(pos + 1);
	}
//	printf("\ncnt:");
//	for (int i = 0; i <= 26; i++){
//		printf("%c:%I64d ", char(i + 'a' - 1), cnt[i]);
//	}
//	printf("\n");
	long long sum = 0, i;
	for (i = 0; i <= 26; i++){
		sum += cnt[i];
		if (sum >= k){
			sum -= cnt[i];
			break;
		}
	}
	string res = find(now + 1, k - sum, all[i]);
	res.push_back(char(i + 'a' - 1));
	return res;
}

int main(){
	scanf("%s", buf), s = buf;
	int k; scanf("%d", &k);
	int n = s.length(), now = 0;
	if (1ll * n * (n + 1) / 2 < k){
		printf("No such line.\n");
		return 0;
	}
	vector <int> pos;
	for (int i = 0; i < n; i++){
		pos.push_back(i);
	}
	string res = find(0, k, pos);
	reverse(res.begin(), res.end());
	printf("%s\n", res.c_str());
	return 0;
}