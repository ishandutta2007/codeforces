#include <iostream>

using namespace std;

const char *a[40] = 
{
	"Washington", "Adams", "Jefferson",
	"Madison", "Monroe", "Adams",
	"Jackson", "Van Buren", "Harrison",
	"Tyler", "Polk", "Taylor", 
	"Fillmore", "Pierce", "Buchanan",
	"Lincoln", "Johnson", "Grant",
	"Hayes", "Garfield", "Arthur",
	"Cleveland", "Harrison", "Cleveland",
	"McKinley", "Roosevelt", "Taft",
	"Wilson", "Harding", "Coolidge",
	"Hoover", "Roosevelt", "Truman",
	"Eisenhower", "Kennedy", "Johnson",
	"Nixon", "Ford", "Carter", "Reagan"
}                                         ;

int main()
{
	int n; cin >> n; cout << a[n - 1];
}