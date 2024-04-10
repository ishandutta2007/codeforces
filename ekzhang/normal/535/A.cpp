#include <string>
#include <iostream>

using namespace std;

string lessTwenty[20] = {"zero", "one", "two", "three", "four",
						 "five", "six", "seven", "eight", "nine",
						 "ten", "eleven", "twelve", "thirteen", "fourteen",
						 "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[10] = {"", "", "twenty", "thirty", "forty", 
				   "fifty", "sixty", "seventy", "eighty", "ninety"};
int n;
string res;

int main() {
	cin >> n;
	if (n < 20) {
		res = lessTwenty[n];
	}
	else {
		int div = n / 10;
		int mod = n % 10;
		res = tens[div];
		if (mod != 0) {
			res += "-" + lessTwenty[mod];
		}
	}
	cout << res << endl;
}