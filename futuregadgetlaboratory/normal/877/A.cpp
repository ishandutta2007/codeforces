#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
const int N = 300033;
const int LOG = 20;
const int MOD = 1e9 + 7;
typedef complex<double> Complex;

int main() {
	set<string> vec = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	string st;
	cin >> st;
	int cnt(0);
	for(int i(0); i < (int)st.size(); i++) {
		for(int j(1); j <= (int)st.size() - i; j++) {
			if(vec.count(st.substr(i, j))) 
				cnt++;
		}
	}
	printf("%s\n", cnt == 1 ? "YES" : "NO");
}