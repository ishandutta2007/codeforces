#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(NULL);
	int n; cin >> n;
	int beg = 0, stp = 0;
	for (int i = 1; i < n; i++)
	{
		stp++;
		beg = (beg + stp) % n;	
		cout << beg + 1 << " ";
	}
}