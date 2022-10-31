#pragma comment (linker, "/STACK:10000000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
  
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e18 + 7)
#define sort stable_sort
 

using namespace std;

int n, a, b;

int main(){
//	ifstream cin("input.txt");
//  ofstream cout ("output.txt");
	cin >> a >> b;
	n = a + b + 1;
	
	int i = 1;
	while (a){
		cout << i << " ";
		i++;
		a--;
	}
	cout << n << " ";
	for (int i = 1; i <= b; i++){
		cout << n - i << " ";
	}
	return 0;
}