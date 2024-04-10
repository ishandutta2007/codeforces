#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <cmath>
#include <fstream>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <cmath>
#include <fstream>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
//ifstream fin("aa.txt");
int main()
{
	int n;
	int sum = 0;
	int a;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
	}
	printf("%f\n",sum*1.0/n);
	return 0;
}