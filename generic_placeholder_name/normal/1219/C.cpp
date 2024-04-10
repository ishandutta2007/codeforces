// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
#define ll  long long 

/*********VARIABLE****************/
using namespace std;
typedef pair<ll,ll> ii;
/******************************/
string s,res;
ll n,i,j,a,b,x,y;
/*********FUNCTIONS**************/
void buildmin(ll x){
	res="";
	
	for (ll ii=1;ii<=(s.length()/x)+1;ii++) { cout<<'1'; for (ll jj=1;jj<x;jj++) cout<<'0';}
}
void build(ll x){
	res="";
	
	for (ll ii=1;ii<=(s.length()/x);ii++) {for (ll jj=0;jj<x;jj++) cout<<s[jj];}
}
int cmp(string a, string b)
{
	
	for (ll ii=0; ii<a.length(); ii++) {if (a[ii]<a[ii%n]) return 1; if (a[ii]>a[ii%n]) return 0;}
	return 0;
}

void pone(ll x){ 
	ll flag=0;
	for (ll ii=x-1; ii>=0; ii--) if ((s[ii]=='9')and(!flag)) s[ii]='0'; else { if (!flag) {s[ii]++; break;} }
	
	if (s[0]=='0') {s[0]='1'; for (ll ii=0; ii<x; ii++) cout<<s[ii]; for (ll ii=x;ii<s.length();ii++) cout<<s[ii%x];  for (ll ii=0;ii<x;ii++) cout<<s[ii];} 
	else { for (ll ii=0; ii<x; ii++) cout<<s[ii]; for (ll ii=x;ii<s.length();ii++) cout<<s[ii%x];}
} 

/***********MAIN**************/

int main(void) 
{
	cin>>n;
	cin>>s;
	if (s.length()%n!=0) {buildmin(n); cout<<res; return 0;}

	if (cmp(s,res)) {build(n); cout<<res;}
	else {
	pone(n);
	
	
} 
}