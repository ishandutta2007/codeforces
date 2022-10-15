#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int k, n; cin >> k >> n;
	vector <int> v(n), q;
	for (int i = 0; i < n; i++) cin >> v[i];
	q = v;
	
	int resmin = 0;
	for (int i = 0; i < k; i++)
	{
		int mv = 0;
		while (v[mv] == 0) mv++;
		for (int j = mv + 1; j < n; j++)                                             
			if (v[j] != 0 && v[j] < v[mv]) mv = j;
		resmin += v[mv];
		v[mv]--;
	}

	v = q;
	int resmax = 0;
	for (int i = 0; i < k; i++)
	{                
		int mv = 0;
		while (v[mv] == 0) mv++;
		for (int j = mv + 1; j < n; j++)                                             
			if (v[j] != 0 && v[j] > v[mv]) mv = j;
		resmax += v[mv];
		v[mv]--;
	}
	cout << resmax << " " << resmin;

}