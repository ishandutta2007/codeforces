#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define S_MUL 0.6f
#define S_LEN 10000
#define T_CNT 8
#define E_CNT 8
double randDouble() {
	return (rand() % 32767) / 32767.0;
}
double distForAllPoints2(double x, double y, 
						vector< pdd > &D) {
	double sum = 0;
	for(int i = D.size()-1; i >= 0; i--) {
		sum += hypot(D[i].first - x, D[i].second - y);
	}
	return sum;
}
double annealing2(vector< pdd > &D) {

	double step = S_LEN;
	double x[E_CNT], y[E_CNT], val[E_CNT];
	double Lx, Ly, Rx, Ry, tx, ty, tcost;
	Lx = Rx = D[0].first;
	Ly = Ry = D[0].second;
	for(int i = 0; i < D.size(); i++) {
		Lx = min(Lx, (double)D[i].first);
		Rx = max(Rx, (double)D[i].first);
		Ly = min(Ly, (double)D[i].second);
		Ry = max(Ry, (double)D[i].second);
	}
	for(int i = 0; i < E_CNT; i++) {
		x[i] = randDouble() * (Rx - Lx) + Lx;
		y[i] = randDouble() * (Ry - Ly) + Ly;
		val[i] = distForAllPoints2(x[i], y[i], D);
	}
	while(step > 0.00001) {
		for(int i = 0; i < E_CNT; i++) {
			for(int j = 0; j < T_CNT; j++) {
				tx = x[i] + randDouble() * 2 * step - step;
				ty = y[i] + randDouble() * 2 * step - step;
				tcost = distForAllPoints2(tx, ty, D);
				if(tcost < val[i]) {
					val[i] = tcost, x[i] = tx, y[i] = ty;
				}
			}
		}
		step *= S_MUL;
	}
	double ret = val[0];
	for(int i = 0; i < E_CNT; i++) {
		ret = min(ret, val[i]);
	}
    return ret;
	//printf("%.0lf\n", ret);
}
double distForAllPoints(double x, double y, 
						vector< pair<int, int> > &D) {
    double ans=0;
    for(int i = 0;i<D.size();i++){
        for(int j = i+1;j<D.size();j++){
            vector<pdd> p{D[i],D[j],mp(x,y)};
            ans=max(ans,annealing2(p));
        }
    }
    return ans;
}

double annealing(vector< pair<int, int> > &D) {
	double step = S_LEN;
	double x[E_CNT], y[E_CNT], val[E_CNT];
	double Lx, Ly, Rx, Ry, tx, ty, tcost;
	Lx = Rx = D[0].first;
	Ly = Ry = D[0].second;
	for(int i = 0; i < D.size(); i++) {
		Lx = min(Lx, (double)D[i].first);
		Rx = max(Rx, (double)D[i].first);
		Ly = min(Ly, (double)D[i].second);
		Ry = max(Ry, (double)D[i].second);
	}
	for(int i = 0; i < E_CNT; i++) {
		x[i] = randDouble() * (Rx - Lx) + Lx;
		y[i] = randDouble() * (Ry - Ly) + Ly;
		val[i] = distForAllPoints(x[i], y[i], D);
	}
	while(step > 0.00001) {
		for(int i = 0; i < E_CNT; i++) {
			for(int j = 0; j < T_CNT; j++) {
				tx = x[i] + randDouble() * 2 * step - step;
				ty = y[i] + randDouble() * 2 * step - step;
				tcost = distForAllPoints(tx, ty, D);
				if(tcost < val[i]) {
					val[i] = tcost, x[i] = tx, y[i] = ty;
				}
			}
		}
		step *= S_MUL;
	}
	double ret = val[0];
	for(int i = 0; i < E_CNT; i++) {
		ret = min(ret, val[i]);
	}
    return ret;
	//printf("%.0lf\n", ret);
}
void solve(){
    vector<pii> v;
    for(int i = 0;i<3;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v.pb(mp(x,y));
    }
    printf("%.12f\n",annealing(v));
}
int main(){
    srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/