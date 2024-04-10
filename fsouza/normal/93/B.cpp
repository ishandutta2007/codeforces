#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const double E = 1e-9;

int main()
{
	int n, m;
	double w;

	scanf("%d %lf %d", &n, &w, &m);
	swap(n, m);

	vector <vector <pair <int, double> > > ret(n);
	vector <double> much(n, 0.0);

	double each = (w*m)/n;

	for (int i = 1; i <= m; i++) {
		int ndiff = 0;
		double have = w;
		for (int j = 0; j < n; j++)
			if (ndiff < 2 && have > E && much[j] < each-E) {
				ndiff ++;
				double put = min(each-much[j], have);
				ret[j].push_back(make_pair(i, put));
				have -= put;
				much[j] += put;
			}
	}
	
	int ok = 1;

	for (int i = 0; i < n; i++)
		if (much[i] < each-E)
			ok = 0;

	if (!ok)
		printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < ret[i].size(); j++) {
				printf("%d %lf", ret[i][j].first, ret[i][j].second);
				if (j+1 < (int)ret[i].size())
					printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}