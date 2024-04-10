#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	string s;
	int x;
	cin >> s >> x;
	puts(((s=="front")^(x==1)?"R":"L"));
}