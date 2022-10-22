#include <bits/stdc++.h>
using namespace std;

map <string, int> mp;
int a[3];

int main(){
	mp["C"] = 0, mp["C#"] = 1, mp["D"] = 2, mp["D#"] = 3, mp["E"] = 4, mp["F"] = 5, mp["F#"] = 6;
	mp["G"] = 7, mp["G#"] = 8, mp["A"] = 9, mp["B"] = 10, mp["H"] = 11;
	string aa, b, c; cin >> aa >> b >> c;
	vector <int> v;
	v.push_back(mp[aa]), v.push_back(mp[b]), v.push_back(mp[c]);
	for (int i = 0; i < 3; i++){
		a[i] = i;
	}
	do {
		if ((v[a[1]] - v[a[0]] + 12) % 12 == 4 && (v[a[2]] - v[a[1]] + 12) % 12 == 3){
			printf("major\n");
			return 0;
		}
		else if ((v[a[1]] - v[a[0]] + 12) % 12 == 3 && (v[a[2]] - v[a[1]] + 12) % 12 == 4){
			printf("minor\n");
			return 0;
		}
	} while (next_permutation(a, a + 3));
	printf("strange\n");
	return 0;
}