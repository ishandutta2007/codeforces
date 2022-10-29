#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>


using namespace std;

typedef pair<int, int> PII;

#define MP(A, B) make_pair(A, B)
#define fi first
#define se second

using namespace std;

#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)


template<class T> inline T& RD(T &);
template<class T0, class T1> inline T0& RD(T0 &x0, T1 &x1){RD(x0), RD(x1); return x0;}

template<class T> inline T& RD(T &x){
    //cin >> x;
    scanf("%d", &x);
    //char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
    //char c; c = getchar(); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
    return x;
}

int ____Case; template<class T> inline void OT(const T &x){
    //if (x == -1) printf("Case %d: NO\n", ++____Case);
    //else printf("Case %d: %d\n", ++____Case, x);
    //printf("%I64d ", x);
    //printf("%.9lf", x);
    printf("%d\n", x);
    //cout << x << endl;
}


const int N = 100020;

PII a[N]; int c[N];
int n,x,y;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif


    REP_1_C(i, --RD(n)){
		RD(x, y); a[i]=MP(x,y);
		if (!c[x]) c[x]=i;
		if (!c[y]) c[y]=i;
	}

	OT(n); REP_1(i, n)
		printf("2 %d %d\n",a[i].fi, a[i].se);

	REP_1(i, n){
		if(i!=c[a[i].fi]) printf("%d %d\n",i,c[a[i].fi]);
		if(i!=c[a[i].se]) printf("%d %d\n",i,c[a[i].se]);
	}
}