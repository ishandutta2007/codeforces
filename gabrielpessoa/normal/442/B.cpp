#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int SIZE = 105;


double prob[SIZE];
int n, x;

double calcular(int pos, double cur, double acc) {
	x++;
	if(pos == n) return cur;
	double respostaTemp = calcular(pos+1, cur, acc);
	double curTemp = cur * (1-prob[pos]) + prob[pos] * acc;
	double accTemp = acc * (1 - prob[pos]);
	if(curTemp > cur) {
		return max(respostaTemp, calcular(pos+1, curTemp, accTemp));
	}
	return respostaTemp;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {	
		scanf("%lf", &prob[i]);
	}
	sort(prob, prob+n);
	ll maior = 1/(prob[n-1]-0.000001);
	double cur = 0, acc = 1;
	for(int i = n - 1; i >= 0 && maior > 0; i--, maior--) {
		cur = cur*(1-prob[i]) + prob[i] * acc;
		acc = acc * (1-prob[i]);
	}
	printf("%.9lf\n", cur);
	//printf("Fora bruta: \n%.9lf\n", calcular(0, 0, 1));
	return 0;
}