#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

namespace IO
{
const int SIZE = 1 << 22;
char buff[SIZE], *p = buff + SIZE;
 
char read_char()
{
    if( p == buff + SIZE )
    {
        fread( buff, 1, SIZE, stdin );
        p = buff;
    }
    return *(p++);
}
 
inline int read_int()
{
    char c;
 
    while( !isdigit( c = read_char() ) );
 
    int r = c-'0';
    while( isdigit( c = read_char() ) ) r = 10*r + c - '0';
 
    return r;
}
}
using namespace IO;


double probs[301][3001];
double comp[301][3001];
double pd[301][3001];
vector<complex<double>> fftree[10];
int n,m;
double tr[3001];

void conquer_brute(int shirt, int st, int ed, int idx) {
	double *ans = tr;
	for (int i = 0; i < ed-st+2; i++) ans[i] = 0;
	//vector< complex<double> > &ans = fftree[idx];
	//ans.assign(ed-st+2,0);
	ans[0] = 1;
	for (int i = st; i <= ed; i++) {
		for (int j = i-st+1; j >= 1; j--) {
			ans[j] = ans[j-1] * probs[shirt][i] + ans[j] * (1-probs[shirt][i]);
		}
		ans[0] *= (1-probs[shirt][i]);
	}
	fftree[idx].assign(tr,tr+(ed-st+2));
}


void solve() {
	n = read_int();
	m = read_int();
	//scanf("%d %d", &n, &m);
	memset(pd,-1,sizeof(pd));
	REP(i,n) REP(j,m) {
		probs[j][i] = read_int() / 1000.0;//scanf("%lf", &probs[j][i]);
		//probs[j][i] /= 1000.0;
	}

	vector<double> all;
	REP(j, m) {
		conquer_brute(j, 0, n-1, 0);
		comp[j][0] = fftree[0][0].real();
		REP(i,n) {
			comp[j][i+1] = fftree[0][i+1].real() + comp[j][i];
			all.push_back(1.0 - comp[j][i]);
		}
	}
	sort(all.begin(), all.end(), greater<double>());

	double ans = 0;
	REP(i, n) ans += all[i];
	printf("%.15f\n", ans);
}

int main() {
    solve();
}