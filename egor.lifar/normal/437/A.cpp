#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


string s, s1, s2, s3;


int main() {
	cin >> s >> s1 >> s2 >> s3;
	int k = 0;;
	if (((s.size()-2) >= 2 * (s1.size()-2) &&( s.size()-2) >= 2 * (s2.size()-2) &&( s.size()-2) >= 2 * (s3.size()-2)) || (2 *( s.size()-2) <= (s1.size()-2) && 2 *( s.size()-2) <= (s2.size()-2) && 2 *( s.size()-2) <= (s3.size()-2))) {
		//cout << "A" << endl;
		//return 0;
		k++;
	}
	if (((s1.size()-2) >= 2 *( s.size()-2) && (s1.size()-2) >= 2 * (s2.size()-2) && (s1.size()-2) >= 2 * (s3.size()-2)) || (2 * (s1.size()-2) <=( s.size()-2) && 2 * (s1.size()-2) <= (s2.size()-2) && 2 * (s1.size()-2) <= (s3.size()-2))) {
		//cout << "B" << endl;
		//return 0;
		k++;
	}
	if (((s2.size()-2) >= 2 * (s1.size()-2) && (s2.size()-2) >= 2 *( s.size()-2) && (s2.size()-2) >=  2 * (s3.size()-2)) || (2 * (s2.size()-2) <= (s1.size()-2) && 2 * (s2.size()-2) <=( s.size()-2) && 2 * (s2.size()-2) <= (s3.size()-2))){
		//cout << "C" << endl;
		//return 0;
		k++;
	}
	if (((s3.size()-2) >= 2 * (s1.size()-2) && (s3.size()-2) >= 2 * (s2.size()-2) && (s3.size()-2) >= 2 *( s.size()-2)) || (2 * (s3.size()-2) <= (s1.size()-2) && 2 * (s3.size()-2) <= (s2.size()-2) && 2 * (s3.size()-2) <=( s.size()-2))){
		//cout << "D" << endl;
		//return 0;
		k++;
	}
	if (k > 1 || k == 0) {
		cout << "C" << endl;
	} else {
	if (((s.size()-2) >= 2 * (s1.size()-2) &&( s.size()-2) >= 2 * (s2.size()-2) &&( s.size()-2) >= 2 * (s3.size()-2)) || (2 *( s.size()-2) <= (s1.size()-2) && 2 *( s.size()-2) <= (s2.size()-2) && 2 *( s.size()-2) <= (s3.size()-2))) {
		cout << "A" << endl;
		return 0;
	}
	if (((s1.size()-2) >= 2 *( s.size()-2) && (s1.size()-2) >= 2 * (s2.size()-2) && (s1.size()-2) >= 2 * (s3.size()-2)) || (2 * (s1.size()-2) <=( s.size()-2) && 2 * (s1.size()-2) <= (s2.size()-2) && 2 * (s1.size()-2) <= (s3.size()-2))) {
		cout << "B" << endl;
		return 0;
	}
	if (((s2.size()-2) >= 2 * (s1.size()-2) && (s2.size()-2) >= 2 *( s.size()-2) && (s2.size()-2) >=  2 * (s3.size()-2)) || (2 * (s2.size()-2) <= (s1.size()-2) && 2 * (s2.size()-2) <=( s.size()-2) && 2 * (s2.size()-2) <= (s3.size()-2))){
		cout << "C" << endl;
		return 0;
	}
	if (((s3.size()-2) >= 2 * (s1.size()-2) && (s3.size()-2) >= 2 * (s2.size()-2) && (s3.size()-2) >= 2 * ( s.size()-2)) || (2 * (s3.size()-2) <= (s1.size()-2) && 2 * (s3.size()-2) <= (s2.size()-2) && 2 * (s3.size()-2) <=( s.size()-2))){
		cout << "D" << endl;
		return 0;
	}
	}
    return 0; 
}