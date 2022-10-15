#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n; cin >> n;
	vector <string> v(n);
	int ans = 6;
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < i; j++)
		{
			int c = 0;
			for (int k = 0; k < 6; k++)
				if (v[i][k] != v[j][k]) c++;	
			if (c == 0) 
			{
				cout << "Test error: " << i << "th and " << j << "th are equal." << endl;
				return 0;
			}			
			ans = min(ans, (c - 1) / 2);
		}                         
	cout << ans;
	return 0;
}