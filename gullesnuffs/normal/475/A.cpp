#include <bits/stdc++.h>

using namespace std;
string s[6]={"+------------------------+",
"|O.O.O.#.#.#.#.#.#.#.#.|D|)",
"|O.O.O.#.#.#.#.#.#.#.#.|.|",
"|O.......................|",
"|O.O.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"};

int main(){
	int k;
	scanf("%d", &k);
	int p=0;
	for(int i=0; i < 11; ++i){
		for(int j=0; j < 4; ++j){
			if(j == 2 && i)
				continue;
			if(p < k)
				s[j+1][i*2+1]='O';
			else
				s[j+1][i*2+1]='#';
			++p;
		}
	}
	for(int i=0; i < 6; ++i)
		cout << s[i] << endl;
}