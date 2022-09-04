#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 500005
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int main(){
	string s,s1;
	cin>>s>>s1;
	cout<<s<<" "<<s1<<endl;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string s2,s3;
		cin>>s2>>s3;
		if(s2==s1)
		s1=s3;
		else if(s2==s)
		s=s3;
		cout<<s<<" "<<s1<<endl;
	}
}