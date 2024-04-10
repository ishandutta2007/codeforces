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
	int n;
	scanf("%d",&n);
	string s[N];
	for(int i=0;i<n;i++)
	cin>>s[i];
	for(int i=n-1;i>0;i--){
		for(int j=0;;j++){
			if(s[i][j]<s[i-1][j]){
				s[i-1]=s[i-1].substr(0,j);
				break;
			}
			else if(s[i][j]>s[i-1][j])
			break;
		}
	}
	for(int i=0;i<n;i++)
	cout<<s[i]<<endl;
}