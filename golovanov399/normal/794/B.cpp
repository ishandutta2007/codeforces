#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int n = nxt();
	int h = nxt();

	for (int i = 1; i < n; ++i) {
		double x = h * sqrt(i) / sqrt(n);
		printf("%.12lf ", x);
	}
	printf("\n");

	return 0;
}