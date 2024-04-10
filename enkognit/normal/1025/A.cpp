#include <bits/stdc++.h>
#define fr front
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define pu push
#define pll pair<ll,ll>
#define len length()

using namespace std;

ll n,m,k,i,j,l,r,x,y;
string s;
map<char,ll> a;

int main()
{
 cin >> n;
 cin >> s;
 if (s.size()==1) {cout << "Yes";exit(0);}
 for (int i=0;i<n;i++) {a[s[i]]++;if (a[s[i]]>1) {cout << "Yes";exit(0);}}
 cout << "No";
 return 0;
}