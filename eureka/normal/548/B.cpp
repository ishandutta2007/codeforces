#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

const int N = 510;
int a[N][N];
int ans[N];

int cal(int a[], int n){
    int ans = 0;
    int cnt = 0;
    for (int i=0; i<n; ++i){
	if (a[i] == 1) cnt ++;
	else cnt = 0;
	ans = max(ans, cnt);
    }
    return ans;
}

int mx(int a[], int n){
    int ans = 0;
    for (int i=0; i<n; ++i) ans = max(ans, a[i]);
    return ans;
}

int main(){
    int h, w, q;
    cin >> h >> w >> q;
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j){
	    cin >> a[i][j];
	}
    for (int i=0; i<h; ++i) ans[i] = cal(a[i], w);
    for (int i=0; i<q; ++i){
	int x, y;
	cin >> x >> y;
	x --, y --;
	a[x][y] ^= 1;
	ans[x] = cal(a[x], w);
	cout << mx(ans, h) << endl;
    }
    return 0;
}