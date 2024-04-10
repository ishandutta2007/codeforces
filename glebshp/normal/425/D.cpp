#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 200 * 1000;
const int magic = 100;

vector <int> pts[size];
bool isfat[size];
int n;

int cross_fat(int a, int b) {
	int dst = b - a;
	int res = 0;
	int p1 = 0, p2 = 0, p3 = 0;
	for (int i = 0; i < (int) pts[a].size(); i++) {
		while (p1 + 1 < (int) pts[b].size() && pts[b][p1] < pts[a][i])
			p1++;
		if (pts[a][i] == pts[b][p1]) {
			while (p2 + 1 < (int) pts[a].size() && pts[a][p2] < pts[a][i] + dst)
				p2++;
			while (p3 + 1 < (int) pts[b].size() && pts[b][p3] < pts[b][p1] + dst)
				p3++;
			if ((pts[a][p2] == pts[a][i] + dst) && (pts[b][p3] == pts[b][p1] + dst))
				res++; 
		}
	}

	return res;
}

vector <pair <int, int> > qs[size];
bool used[size];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    int mx = 0;
    int x, y;

    for (int i = 0; i < n; i++) {
    	scanf("%d%d", &x, &y);
    	mx = max(mx, x);
    	pts[x].pb(y);
    }

    vector <int> fat;
    for (int i = 0; i <= mx; i++) {
    	sort(pts[i].begin(), pts[i].end());
    	if ((int) pts[i].size() >= magic) {
    		fat.pb(i); 
       		isfat[i] = true;
       	}
    }

    int ans = 0;
    sort(fat.begin(), fat.end());
    //cerr << fat.size() << endl;
    for (int i = 0; i < (int) fat.size(); i++)
    	for (int j = i + 1; j < (int) fat.size(); j++)
    		ans += 2 * cross_fat(fat[i], fat[j]);
    //cerr << "here" << endl;
    //cerr << mx << endl;

    for (int i = 0; i <= mx; i++)
    	if (!isfat[i]) {
    //		cerr << "huy" << endl;
    		for (int j = 0; j < (int) pts[i].size(); j++)
    			for (int k = j + 1; k < (int) pts[i].size(); k++) {
    //				cerr << i << ' ' << j << ' ' << k << endl;
    				int dst = pts[i][k] - pts[i][j];
    				if (i - dst >= 0) {
    					qs[i - dst].pb(mp(pts[i][j], pts[i][k]));
    				}
    				if (i + dst <= mx) {
    					qs[i + dst].pb(mp(pts[i][j], pts[i][k]));
    				}
    			}
    	}
    //cerr << "here" << endl;
    for (int i = 0; i <= mx; i++) {
    	for (int j = 0; j < (int) pts[i].size(); j++)
    		used[pts[i][j]] = true;
       	for (int j = 0; j < (int) qs[i].size(); j++)
       		if (used[qs[i][j].fs] && used[qs[i][j].sc]) {
       			if (isfat[i])
       				ans += 2;
       			else
       				ans++;
       		}
    	for (int j = 0; j < (int) pts[i].size(); j++)
    		used[pts[i][j]] = false;	
    }

    cout << ans / 2 << endl;
   	

    return 0;
}