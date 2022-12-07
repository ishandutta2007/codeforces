#include <bits/stdc++.h>
using namespace std;

int n, i, j;
int t [1001];
bool occ [1001];
vector <int> out;


int main ()
	{
	scanf ("%d",&n);
	for (i=0; i!=n; i++)
		scanf ("%d",&t[i]);
	for (i=(n-1); i>=0; i--)
		if (occ[t[i]]==false)
			{
			out.push_back(t[i]);
			occ[t[i]]=true;
			}
	printf ("%d\n",out.size());
	for (i=out.size()-1; i>=0; i--)
		printf ("%d ",out[i]);
	printf ("\n");
	
	
	return 0;
	}