#include "bits/stdc++.h"
using namespace std;
 
#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl
 
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pis pair<int,string>
#define psi pair<string,int>
const int inf = 1000000001;
const ll INF = 1e18;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<<fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

int main(){
  string s;
  cin >> s;
  int num0 = 0, num1 = 0;
  vii retu;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (num1 > 0) {
	retu[num1 - 1].push_back(i + 1);
	num1--;
	num0++;
      }
      else {
	retu.push_back(vi(1, i + 1));
	num0++;
      }
    }
    else {
      if (num0 == 0) {
	cout << -1 << endl;
	return 0;
      }
      else {
	retu[num1].push_back(i + 1);
	num0--;
	num1++;
      }
    }
  }
  if (num1 > 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << retu.size() << endl;
  for (int i = 0; i < retu.size(); i++) {
    cout << retu[i].size() << " ";
    for (int j = 0; j < retu[i].size(); j++) {
      cout << retu[i][j]<< " ";
    }
    cout << endl;
  }
}