#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


int inf = 1e9;
long long big_inf = 1e18;


int main(){
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int i = 1;
	while (true){
		if (i % 2){
			if (a < i){
				cout << "Vladik";
				break;
			}

			a -= i;
		}
		else{
			if (b < i){
				cout << "Valera";
				break;
			}
			

			b -= i;
		}

		++i;
	}

	return 0;
}