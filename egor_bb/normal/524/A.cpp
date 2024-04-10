#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
 
#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
 
 
const int INF = int(1e9) + 7;
const int INFll = int(1e18) + 7;
const int SZ = 70;
 
using namespace std;
 


int m, K, a[10005], p = 1;	
map <int , int> num;
vector <vector <int> > g;
vector < vector <int> > ans;
pii b[10004];

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".out");
   cin >> m >> K;
   g.resize(10000);
   ans.resize(10000);
   for (int i = 0; i < m; i++){
	   int t1, t2, p1, p2;
	   cin >> t1 >> t2;
	   if (num[t1]) p1 = num[t1];
	   else {
		   num[t1] = p;
		   a[p] = t1;
		   b[p] = mp(t1, p);
		   p1 = p++;
	   }
	   if (num[t2]) p2 = num[t2];
	   else {
		   num[t2] = p;
		   a[p] = t2;
		   b[p] = mp(t2, p);
		   p2 = p++;
	   }
	   g[p1].push_back(p2);
	   g[p2].push_back(p1);
   }
   sort(b + 1, b + p);
   vector <int> used;
   for (int i = 1; i < p; i++){
	   int k = (g[i].size() * K + 99) / 100;
	   used.assign(p + 2, 0);
	   for (int j = 0; j < g[i].size(); j++){
		   used[g[i][j]] = 1;
	   }
	   for (int j = 1; j < p; j++){
		   if (j != i && !used[j]){
			   int cnt = 0;
			   for (int q = 0; q < g[j].size(); q++){
				   if (used[g[j][q]]) cnt++;
			   }
			   if (cnt >= k) ans[i].push_back(j);
		   }
	   }
   }
   for (int i = 1; i < p; i++){
	   int j = b[i].second, nn = b[i].first;
	   cout << nn << ": ";
	   cout << ans[j].size() << " ";
	   for (int q = 0; q < ans[j].size(); q++){
		   ans[j][q] = a[ans[j][q]];
	   }
	   sort(ans[j].begin(), ans[j].end());
	   for (int q =0 ; q < ans[j].size(); q++){
		   cout << ans[j][q] << " ";
	   }
	   cout << '\n';
   }
}