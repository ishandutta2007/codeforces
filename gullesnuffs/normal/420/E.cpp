#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
#define EPS 0.00000001
#define PI 3.14159265359
using namespace std;

vector<pair<double, bool> > ev;

void add(bool good, double ang){
	for(int i=0; i <= 4; ++i){
		ev.push_back(make_pair(ang+PI*2*i, good));
	}
}

int main(){
	int n;
	double d;
	scanf("%d%lf", &n, &d);
	for(int i=0; i < n; ++i){
		double x, y, r;
		scanf("%lf%lf%lf", &x, &y, &r);
		double genAng = atan2(y, x);
		double a=sqrt(x*x+y*y);
		for(double b=d; b <= a+r+EPS; b += d){
			if(b+r < a-EPS)
				continue;
			double Cos=(a*a+b*b-r*r)/(2*a*b);
			if(Cos > 1)Cos=1;
			if(Cos < -1)Cos=-1;
			double v=acos(Cos)+EPS;
			add(1, genAng-v);
			add(0, genAng+v);
		}
	}
	sort(ev.begin(), ev.end());
	int sum=0;
	int ans=0;
	for(int i=0; i < ev.size(); ++i){
		sum += (ev[i].second?1:-1);
		if(sum > ans)
			ans=sum;
	}
	printf("%d\n", ans);
	return 0;
}