#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265359

pair<double, double> pontos[100005];
double raio2[100005];

int main() {
	int n, x, y;
	double menor = 1e15, maior = 0;
	scanf("%d %d %d", &n, &x, &y);
	for(int i = 1; i <= n; i++) {
		int xLendo, yLendo;
		scanf("%d %d", &xLendo, &yLendo);
		pontos[i] = make_pair(xLendo - x, yLendo - y);
		raio2[i] = pontos[i].first * pontos[i].first + pontos[i].second * pontos[i].second;
	}
	pontos[0] = pontos[n];
	for(int i = 1; i <= n; i++) {
		maior = max(maior, raio2[i]);
		menor = min(menor, raio2[i]);
		pair<double, double> v = make_pair(pontos[i].first-pontos[i-1].first, pontos[i].second-pontos[i-1].second);
		double projection = (-pontos[i-1].first * v.first + -pontos[i-1].second * v.second)/(v.first*v.first + v.second*v.second);
		pair<double, double> r =  make_pair(projection * v.first + pontos[i-1].first, projection * v.second + pontos[i-1].second);
		if(r.first >= min(pontos[i].first, pontos[i-1].first) && r.first <= max(pontos[i].first, pontos[i-1].first) && r.second >= min(pontos[i].second, pontos[i-1].second) && r.second <= max(pontos[i].second, pontos[i-1].second)) {
			menor = min(menor, r.first*r.first + r.second * r.second);
		}
	}
	
	printf("%.8f\n", (maior-menor)*PI);
}