#include<cstdio>
#include<vector>
int n;
int sl[500100][2];
int dl[500100][2];
int en[500100][2];
std::vector<int> el[1100000];
std::vector<int> ed[1100000];
int usec[1100000];
int echk[1100000];
int conn[1100000][2];
int eord[1100000];
void nodeinit(int x) {
	el[x].clear();
	ed[x].clear();
	usec[x] = 0;
}
int para(int ansx) {
	for (int i = 0; i < n; i++) {
		dl[i][0] = sl[i][0] & ((1 << ansx) - 1);
		dl[i][1] = sl[i][1] & ((1 << ansx) - 1);
	}
	for (int i = 0; i < n; i++) {
		nodeinit(dl[i][0]);
		nodeinit(dl[i][1]);
		echk[i] = 0;
	}
	int oddcnt = 0;
	for (int i = 0; i < n; i++) {
		en[i][0] = el[dl[i][0]].size();
		el[dl[i][0]].push_back(dl[i][1]);
		ed[dl[i][0]].push_back(i * 2);
		if (el[dl[i][0]].size() % 2 == 0) {
			oddcnt--;
		}
		else {
			oddcnt++;
		}
		en[i][1] = el[dl[i][1]].size();
		el[dl[i][1]].push_back(dl[i][0]);
		ed[dl[i][1]].push_back(i * 2 + 1);
		if (el[dl[i][1]].size() % 2 == 0) {
			oddcnt--;
		}
		else {
			oddcnt++;
		}
		//printf("d %d %d\n", dl[i][0], dl[i][1]);
	}
	if (oddcnt > 0)return 0;
	int curloc = dl[0][0];
	int usedeg = 0;
	int lue = n + 1;
	int bne = n + 1;
	while (1) {
		//printf("%d %d %d %d %d %d %d\n", ansx, curloc, usedeg, lue, bne, usec[curloc], el[curloc].size());
		if (usec[curloc] == el[curloc].size()) {
			//printf("usedall\n");
			if (bne == n + 1) {
				if (lue == n + 1)break;
				curloc = dl[lue][0] ^ dl[lue][1] ^ curloc;
				bne = lue;
				lue = conn[lue][0];
				continue;
			}
			else {
				conn[lue][1] = bne;
				conn[bne][0] = lue;
				bne = n + 1;
				continue;
			}
		}
		int pel = el[curloc][usec[curloc]];
		int ped = ed[curloc][usec[curloc]];
		usec[curloc]++;
		int cue = ped / 2;
		if (echk[cue] != 0)continue;
		//printf("s %d %d\n", pel, ped);
		echk[cue] = 1;
		usedeg++;
		conn[lue][1] = cue;
		conn[cue][0] = lue;
		conn[cue][1] = n + 1;
		eord[cue] = ped % 2;
		curloc = pel;
		lue = cue;
	}
	if (usedeg == n) {
		return 1;
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &sl[i][0], &sl[i][1]);
	}
	int ans = -1;
	for (int i = 4; i >= 0; i--) {
		ans += 1 << i;
		if (ans > 20 || para(ans) == 0)ans -= 1 << i;
	}
	para(ans);
	printf("%d\n", ans);
	int pn = n + 1;
	while (conn[pn][1] != n + 1) {
		pn = conn[pn][1];
		printf("%d %d ", pn * 2 + 1 + eord[pn], pn * 2 + 2 - eord[pn]);
	}
	return 0;
}