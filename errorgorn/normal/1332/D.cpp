#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int k;
const int filled=262144-1;
const int big=131072;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>k;
	cout<<3<<" "<<2<<endl;
	cout<<filled<<" "<<k<<endl;
	cout<<big<<" "<<filled<<endl;
	cout<<0<<" "<<(filled>>1)<<endl;
}