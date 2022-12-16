#include <bits/stdc++.h>
using namespace std;

bool events[300005];
vector<int> app[300005];
int appPointers[300005];
int firstReadApp[300005];
	
int main() {
	int n, q, t, x;
	int eventPointer = 0, unread = 0, firstRead = 0;
	memset(events, 0, sizeof(events));
	memset(app, 0, sizeof(app));
	memset(appPointers, 0, sizeof(appPointers));
	memset(firstReadApp, 0, sizeof(firstReadApp));
	scanf("%d %d", &n, &q);
	for(int i = 0; i < q; i++) { 
		scanf("%d %d", &t, &x);
		if(t == 1) {
			app[x].push_back(eventPointer++);
			appPointers[x]++;
			unread++;
		} else if(t == 2) {
			for(int i = firstReadApp[x]; i < appPointers[x]; i++) {
				if(!events[app[x][i]]) {
					unread--;
					events[app[x][i]] = true;
				}
			}
			firstReadApp[x] = appPointers[x];
		} else if(t == 3) {
			for(int i = firstRead; i < x; i++) {
				if(!events[i]) {
					unread--;
					events[i] = true;
				}
			}
			firstRead = max(x, firstRead);
		}
		printf("%d\n", unread);
	}
	return 0;
}