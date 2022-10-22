#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<pair<pair<int, int>, double> > v;
int a[100005];
double p2[5005][10005];
int M;

int rec(int i){
	vector<int> js;
	int j;
	int m=0;
	int l=v[i].first.first;
	for(j=i+1; j < v.size(); ){
		if(v[j].first.first >= -v[i].first.second)
			break;
		for(int k=l; k < v[j].first.first; ++k)
			m=max(m, a[k]);
		js.push_back(j);
		l=-v[j].first.second;
		j=rec(j);
	}
	for(int k=l; k < -v[i].first.second; ++k)
		m=max(m, a[k]);
	for(int k=10000; k >= 0; --k){
		double np=1;
		for(int m=0; m < js.size(); ++m){
			double tmpp=p2[js[m]][k-1]*v[js[m]].second+p2[js[m]][k]*(1-v[js[m]].second);
			np*=1-tmpp;
		}
		p2[i][k]=1-np;
		if(m-M >= (k-5000))
			p2[i][k]=1;
		//if(p2[i][k] < 1-1e-9 && p2[i][k] > 1e-9)
		//	printf("p2[%d][%d]=%lf\n", i, k, p2[i][k]);
	}
	return j;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		M=max(M, a[i]);
	}
	for(int i=0; i < q; ++i){
		int l, r;
		double p;
		scanf("%d%d%lf", &l, &r, &p);
		--l;
		v.push_back(make_pair(make_pair(l, -r), p));
	}
	v.push_back(make_pair(make_pair(0, -n), 0));
	sort(v.begin(), v.end());
	rec(0);
	double ans=M;
	for(int i=5001; i <= 10000; ++i)
		ans += p2[0][i];
	printf("%.7lf\n", ans);
}