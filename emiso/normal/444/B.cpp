#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x;
int a[100010], b[100010], n, d, pos[100010], c[100010];
vector<int> blist;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i++) {
		pos[a[i]] = i;
		if(b[i]) blist.push_back(i);
	}
}

int main() {
	scanf("%d %d %lld", &n, &d, &x);
	initAB();
	
	if(d <= 2000) {
		for(int v = 1, i; v <= n; v++) {
			i = pos[v];
			for(int &j : blist) {
				if(i + j >= n) break;
				c[i+j] = v;
			}
		} 	
	} else {
		vector<int> notyet, tmp;
		for(int i = 0; i < n; i++) notyet.push_back(i);
		for(int v = n; v > 0; v--) {
			int i = pos[v];
			
			for(int &p : notyet)
				if(i <= p && b[p-i]) c[p] = v;

			for(int &p : notyet)
				if(c[p] == 0) tmp.push_back(p);
				
			if(tmp.empty()) break;
			notyet = tmp;
			tmp.clear();
		}
	}
	
	for(int i = 0; i < n; i++)
		printf("%d\n", c[i]);
	return 0;
}