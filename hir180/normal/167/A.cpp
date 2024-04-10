#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a,d;
	scanf("%d %d %d",&n,&a,&d);
	vector<double>vec;
	for(int i=0;i<n;i++)
	{
		double b,ac; scanf("%lf %lf",&b,&ac);
		double lb = 0, ub = 1e9, mid;
		for(int j=0;j<1000;j++)
		{
			mid = (lb+ub)/2.0;
			if(mid <= ac/a)
			{
				if(mid*(mid*a)/2 < 1.0*d) lb=mid;
				else ub=mid;
			}
			else
			{
				if(ac*ac/a/2+ac*(mid-ac/a) < 1.0*d) lb=mid;
				else ub=mid;
			}
		}
		double t = b + mid;
		vec.push_back(t);
	}
	double s = 0.0;
	for(int i=0;i<vec.size();i++) printf("%f\n",(s=max(s,vec[i])));
}