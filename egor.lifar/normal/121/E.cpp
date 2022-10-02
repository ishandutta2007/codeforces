#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


#define INF 1000000000
#define count count1


int n, m;
int v[34];
int ll[100000];
pair<int, int> d[600001];
int d1[600001];
int count[600001];
int mod[600001];
int mod1[600001];
int a[300001];
int ss = 1;


bool good(int a) {
    vector<int> b;
    while (a > 0) {
        b.push_back(a % 10);
        a /= 10;
    }
    for (int i = 0; i < (int)b.size(); i++) {
        if (b[i] != 4 && b[i] != 7) {
            return 0;
        }
    }
    return 1;
}


inline void push(int v) {
	int ss1 = (ss << 1);
	int v2 = (v << 1);
	if (v < ss1) {
	    if (mod[v] != 0) {
	        d[v].first += mod[v];
	        if (v2 < ss1) {
	    	    mod[v2] += mod[v];
	    	    mod[v2 + 1] += mod[v];
	    	}
	        mod[v] = 0;
	    }
	}
}


inline void push1(int v) {
    if (mod1[v] != 0) {
    	int v2 = (v << 1);
        d1[v] += mod1[v];
        if (v2 < (ss << 1)) {
       		mod1[v2] += mod1[v];
        	mod1[v2 + 1] += mod1[v];
    	}
        mod1[v] = 0;
    }
}


inline void update(int v) {
	if (v < ss) {
		int v2 = (v << 1);
	    count[v] = 0;
	    d[v] = min(make_pair(d[v2].first + mod[v2], d[v2].second), make_pair(d[v2 + 1].first + mod[v2 + 1], d[v2 + 1].second));
	    if (d[v].first == d[v2].first + mod[v2]) {
	        count[v] += count[v2];
	    }
	    if (d[v].first == d[v2 + 1].first + mod[v2 + 1]) {
	        count[v] += count[v2 + 1];
	    }
	}	
} 


inline void change(int i, int a) {
    int i1 = i;
    vector<int> v;
    while (i1 > 0) {
        v.push_back(i1);
        i1 = (i1 >> 1);
    }
    for (int j = (int)v.size() - 1; j >= 0; j--) {
        int h = v[j];
        push(h);
        int h1 = (h << 1);
        push(h1);
        push(h1 + 1);
    }
    for (int j = 1; j < (int)v.size(); j++) {
        int h = v[j];
        update(h);
    }
    d[i].first = a;
    d[i].second = i - ss + 1;
    count[i] = 1;
    while ((i >> 1) > 0) {
        i = (i >> 1);
        update(i);
    }
}    



inline void change1(int i, int a) {
    d1[i] = a;
    while ((i >> 1) > 0) {
        i = (i >> 1);
        int i2 = (i << 1);
        d1[i] = min(d1[i2], d1[i2 + 1]);
    }
}


bool bbb = false;


pair<pair<int, int>, int > rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return make_pair(make_pair(INF, INF), INF);
    }
    if (l <= vl && vr <= r) {
        return make_pair(make_pair(d[v].first + mod[v], d[v].second), count[v]);
    }
    push(v);
    int vm = (vl + vr) >> 1;
    int v1 = (v << 1);
    pair<pair<int, int>, int > a = rmq(v1, vl, vm , l, r);
    pair<pair<int, int>, int > b = rmq(v1 + 1, vm  + 1, vr, l, r);
    int f = min(a.first.first, b.first.first);
    int g = 0;
    if (a.first.first == f) {
        g += a.second;
    }
    if (b.first.first == f) {
        g += b.second;
    }
    pair<pair<int, int>, int > ans = make_pair(min(a.first, b.first), g);
    update(v);
    return ans;
}


int rmq1(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return INF;
    }
    if (l <= vl && vr <= r) {
        return d1[v] + mod1[v];
    }
    push1(v);
    int vm = (vl + vr) >> 1;
    int v1 = (v << 1);
    int ans = min(rmq1(v1, vl, vm , l, r), rmq1(v1 + 1, vm  + 1, vr, l, r));
    d1[v] = min(d1[v1] + mod1[v1], d1[v1 + 1] + mod1[v1 + 1]);
    return ans;
}



void add(int v, int vl, int vr, int l, int r, int a) {
    if (l <= vl && vr <= r) {
        mod[v] += a;
        return;
    }
    push(v);
    int vm = (vl + vr) >> 1;
    int v1 = (v << 1);
    if (!(vl > r || vm < l)) {
    	add(v1, vl, vm , l, r, a);
	}
	if (!(vm + 1 > r || vr < l)) {
    	add(v1 + 1, vm + 1, vr, l, r, a);
	}
    update(v);
}
//


void add1(int v, int vl, int vr, int l, int r, int a) {
    if (l <= vl && vr <= r) {
        mod1[v] += a;
        return;
    }
    push1(v);
    int vm = (vl + vr) >> 1;
    int v1 = (v << 1);
    if (!(vl > r || vm < l)) {
    	add1(v1, vl, vm, l, r, a);
	}
	if (!(vm + 1 > r || vr < l)) {
   	 	add1(v1 + 1, vm + 1, vr, l, r, a);
	}
    d1[v] = min(d1[v1] + mod1[v1], d1[v1 + 1] + mod1[v1 + 1]);
}


int l, r, k;


int main() {
   	scanf("%d %d", &n, &m);
    int l1 = 0;
    for (int i = 1; i <= 10000; i++) {
        if (good(i)) {
            v[l1] = i;
            l1++;
        //    cout << i << endl;
        }
    }
    v[l1] = 10002;
    while (ss < n) {
        ss = (ss << 1);
    }
    for (int i = 1; i < (ss << 1); i++) {
        d[i] = make_pair(INF, 0);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        change1(i + ss, a[i]);
        int a = i;
        int sss = rmq1(1, 1, ss, a + 1, a + 1);
	    while (sss > v[ll[a]]) {
	        ll[a]++;
	    }	    
	    change(ss + a, v[ll[a]] - sss);
	}
    for (int k1 = 0; k1 < m; k1++) {
        char c[7];
        scanf("%s", c);
        if (string(c) == "add") {
            scanf(" %d %d %d", &l, &r, &k);
            add1(1, 1, ss, l, r, k);
            add(1, 1, ss, l, r, -k);
            while (true) {
            	pair<pair<int, int>, int> a1 = make_pair(make_pair(d[1].first + mod[1], d[1].second), count[1]);
            	if (a1.first.first >= 0) {
            		break;
            	}
            	int a = a1.first.second - 1;
                int sss = rmq1(1, 1, ss, a + 1, a + 1);
			    while (sss > v[ll[a]]) {
			        ll[a]++;
			    }	    
			    add(1, 1, ss, a + 1, a + 1, (v[ll[a]] - sss) - a1.first.first);
            }
        } else {
            scanf(" %d %d", &l, &r);
            pair<pair<int, int>, int> a = rmq(1, 1, ss, l, r);
            if (a.first.first == 0) {
                printf("%d\n", a.second);
            } else {
                printf("%d\n", 0);
            }
        }
      //  cout << k1 + 1 << endl;
    }
    return 0;
}