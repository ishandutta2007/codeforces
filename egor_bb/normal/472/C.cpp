#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

#define INF 1000000009
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back

using namespace std;


int n;
string s[100005][2];

int main(){
	//ifstream in ("in.txt");
	cin >> n ;
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> s[i][0] >> s[i][1];
	int perm[100005];
	for (int i =0 ; i < n; i++){
		cin >> perm[i];
		perm[i]--;
	}
	string now;
	if (s[perm[0]][0] < s[perm[0]][1]) now = s[perm[0]][0];
	else now = s[perm[0]][1];
	for (int i = 1; i < n; i++){
		int t = i;
		i = perm[i];
		if (s[i][0] > now){
			if (s[i][1] > now){
				if (s[i][1] > s[i][0]) now = s[i][0];
				else now = s[i][1];
			} else {
				now = s[i][0];
			}
		} else if (s[i][1] > now) now = s[i][1];
		else {
			cout << "NO";
			return 0;
		}
		i = t;
	}
	cout << "YES";
}