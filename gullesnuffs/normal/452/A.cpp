#include <string>
#include <iostream>
#include <cstdio>
#define MOD 1000000007
typedef long long LL;

using namespace std;

string evo[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main(){
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	for(int i=0; i < 8; ++i){
		bool ok=1;
		if(evo[i].size() != n)
			continue;
		for(int j=0; j < evo[i].size(); ++j)
			if(evo[i][j] != s[j] && s[j] != '.')
				ok=0;
		if(ok){
			cout << evo[i] << endl;
		}
	}

}