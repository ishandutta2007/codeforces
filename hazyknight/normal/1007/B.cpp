#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

int T;
int a,b,c;
int sum[100005];

vector<int> divs[3];

bool have[3][100005];

void divide(int p,int id,bool tp)
{
	divs[id].clear();
	for (int i = 1;i * i <= p;i++)
		if (p % i == 0)
		{
			if (i * i == p)
			{
				if (tp)
					divs[id].push_back(i);
				have[id][i] = tp;
			}
			else
			{
				if (tp)
				{
					divs[id].push_back(i);
					divs[id].push_back(p / i);
				}
				have[id][i] = have[id][p / i] = tp;
			}
		}
}

int C2(int v)
{
	return v * (v - 1) / 2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		divide(a,0,1);
		divide(b,1,1);
		divide(c,2,1);
		int A = 0,B = 0,C = 0,AB = 0,BC = 0,AC = 0,ABC = 0;
		for (int i = 0;i < divs[0].size();i++)
		{
			int v = divs[0][i];
			if (have[0][v])
			{
				if (have[1][v] && have[2][v])
					ABC++;
				else if (have[1][v])
					AB++;
				else if (have[2][v])
					AC++;
				else
					A++;
			}
		}
		for (int i = 0;i < divs[1].size();i++)
		{
			int v = divs[1][i];
			if (have[1][v])
			{
				if (have[0][v] && have[2][v])
					ABC++;
				else if (have[0][v])
					AB++;
				else if (have[2][v])
					BC++;
				else
					B++;
			}
		}
		for (int i = 0;i < divs[2].size();i++)
		{
			int v = divs[2][i];
			if (have[2][v])
			{
				if (have[0][v] && have[1][v])
					ABC++;
				else if (have[0][v])
					AC++;
				else if (have[1][v])
					BC++;
				else
					C++;
			}
		}
		AB /= 2;
		BC /= 2;
		AC /= 2;
		ABC /= 3;
	//	cout << A << ' '<< B << ' ' << C << ' ' << AB << ' ' <<BC << ' '<<AC << ' ' <<ABC << endl; 
		int ans1 = ABC;
		int ans2 = ABC * (ABC - 1) + ABC * (AB + BC + AC + A + B + C) + ABC * (AB + BC + AC) + AB * BC * 2 + BC * AC * 2 + AB * AC * 2 + AB * C + BC * A + AC * B;
		int ans3 = ABC * (ABC - 1) * (ABC - 2) / 6 + C2(ABC) * (A + B + C + AB + BC + AC) + ABC * (C2(AB) + C2(BC) + C2(AC) + AB * BC + AB * AC + BC * AC + (AB + BC + AC) * (A + B + C) + A * B + B * C + A * C) + C2(AB) * BC + AB * C2(BC) + C2(BC) * AC + BC * C2(AC) + C2(AB) * AC + AB * C2(AC) + C2(AB) * C + C2(BC) * A + C2(AC) * B + A * B * C + (AB * BC + BC * AC + AB * AC) * (A + B + C) + (AB + BC + AC) * (A * B + B * C + C * A) - AB * A * B - BC * B * C - AC * C * A + AB * BC * AC;
	//	cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
		cout << ans1 + ans2 + ans3 << endl;
		divide(a,0,0);
		divide(b,1,0);
		divide(c,2,0);
	}
	return 0;
}