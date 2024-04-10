#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}

#define max_n 100005


using namespace std;

lint n,d,x;
VI a,b;

lint getNextX() {
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
}

int pos[100005];
int ile = 0;
VI c;

void add(int k, int p){
	if(c[p]==0){
		c[p] = k;
		ile++;
	}
}


int main(){
	cin>>n>>d>>x;
	a.reserve(n); b.reserve(n);
	initAB();
	c.reserve(n);
	FOR(i,0,n) c[i] = 0;

	VI tam; FOR(i,0,n) if(b[i]) tam.pb(i);
	FOR(i,0,n) pos[a[i]] = i;
	
	int u = sqrt(n);
	FOR(i,0,2*u){
		FOR(j,0,i+1)
			c[i] = max(c[i],a[j]*b[i-j]);
		ile++;
	}

	FORD(i,n,1){
		FOR(j,0,tam.size()){
			if(tam[j]+pos[i]<n) add(i,tam[j]+pos[i]);
			else break;
		}
		if(ile==n) break;
	}

	FOR(i,0,n) printf("%d\n",c[i]);


	return 0;
}