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

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int d = 0;
	if(a*c%b != 0) d = 1;
	cout <<  a*c/b-c+d <<endl;
	return 0;
}