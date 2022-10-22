#include <bits/stdc++.h>
using namespace std;

char s[110];
int vis[26], used[26];

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", s);
		int n = strlen(s);
		memset(vis, 0, sizeof(vis));
		int tot = 0;
		for (int i = 0; i < n; i++){
			vis[s[i] - 'a']++;
			if (vis[s[i] - 'a'] == 1) tot++;
		}
		int pos = 0;
		for (int i = 0; i < 26; i++){
			if (vis[i]){
				pos = i; break;
			}
		}
		vector <int> res;
		for (int i = pos; i < 26; i += 2){
			if (vis[i]) res.push_back(i), tot--;
		}
		int flag = 1;
		memset(used, 0, sizeof(used));
		while (flag){
			flag = 0;
			for (int i = pos + 1; i < 26; i += 2){
				if (used[i] || vis[i] == 0) continue;
				for (int j = res.size(); j >= 0; j--){
					int pd = 1;
					if (j && (res[j - 1] == i - 1 || res[j - 1] == i + 1)) pd = 0;
					if (j != res.size() && (res[j] == i + 1 || res[j] == i - 1)) pd = 0;
					if (pd){
						tot--, flag = 1, res.insert(res.begin() + j, i), used[i] = 1;
						break;
					}
				}
			}
		}
		if (tot != 0) printf("No answer\n");
		else {
			for (int i = 0; i < res.size(); i++){
				for (int j = 0; j < vis[res[i]]; j++){
					printf("%c", char(res[i] + 'a'));
				}
			}
			printf("\n");
		}
	}
	return 0;
}