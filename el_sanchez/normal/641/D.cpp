#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
#define X first
#define Y second


const int maxn = (int)1e5 + 100;
double alpha[maxn], beta[maxn];
double a[maxn], b[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lf", &beta[i]);
	for (int i = 0; i < n; i++) scanf("%lf", &alpha[i]);
	ld Sa = 0, Sb = 0;
	for (int i = 0; i < n; i++)
	{
		ld c = alpha[i] + beta[i];
		ld A = 1, B = -(c + (Sb - Sa)), C = beta[i] - c * Sa;
		//cout << "A=" << A << "; B=" << B << "; C=" << C << endl;
		ld x1 = (-B + sqrt(max(0.,B*B - 4.*A*C))) / 2.;
		//ld x2 = (-B - sqrt(B*B - 4.*A*C)) / 2.;
		ld y1 = c - x1;
		//ld y2 = c - x2;
		//cout << "x1=" << x2 << " y1=" << y2 << endl;
		
		a[i] = x1;
		b[i] = y1;			
		
		Sa += a[i];
		Sb += b[i];
	}
	cout.precision(15);
	for (int i = 0; i < n; i++)
	   printf("%.9lf ", a[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
	   printf("%.9lf ", b[i]);
	printf("\n");
	return 0;
}