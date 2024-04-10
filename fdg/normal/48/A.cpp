#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

set < pair<string,string> > f;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	string a,b,c;
	cin >> a >> b >> c;
	f.insert(make_pair("rock","scissors"));
	f.insert(make_pair("paper","rock"));
	f.insert(make_pair("scissors","paper"));
	if (f.count(make_pair(a,b))&&f.count(make_pair(a,c))) cout << "F" << endl;
	else if (f.count(make_pair(b,a))&&f.count(make_pair(b,c))) cout << "M" << endl;
	else if (f.count(make_pair(c,a))&&f.count(make_pair(c,b))) cout << "S" << endl;
	else cout << "?\n";
	return 0;
}