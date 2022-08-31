#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e5+1;
int n,q;
ll a[N];
vector<int>v={1200,1400,1600,1900,2100,2300,2400,2600,3000};
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int x;cin >> x;cout << *upper_bound(v.begin(),v.end(),x) << '\n';
}