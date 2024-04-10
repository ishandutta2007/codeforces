#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int a,b,c,d,n;
vector<int>x,y;
int ar[100005];
bool check(){
	for(int i=1;i<n;i++){
		if(abs(ar[i-1]-ar[i]) != 1) return false;
	}
	return true;
}
int main(){
	cin >> a >> b >> c >> d;
	n = a+b+c+d;
	rep(i,n){
		if(i%2 == 0) x.pb(i);
		else y.pb(i);
	}
	if(a+c == x.size() && b+d == y.size()){
		rep(i,x.size()){
			if(i < a) ar[x[i]] = 0;
			else ar[x[i]] = 2;
		}
		rep(j,y.size()){
			if(j < d) ar[y[y.size()-1-j]] = 3;
			else ar[y[y.size()-1-j]] = 1;
		}
		if(check()){
			puts("YES");
			rep(i,n) printf("%d\n",ar[i]);
			return 0;
		}
	}
	if(b+d == x.size() && a+c == y.size()){
		rep(i,x.size()){
			if(i < d) ar[x[i]] = 3;
			else ar[x[i]] = 1;
		}
		rep(j,y.size()){
			if(j < a) ar[y[y.size()-1-j]] = 0;
			else ar[y[y.size()-1-j]] = 2;
		}
		if(check()){
			puts("YES");
			rep(i,n) printf("%d\n",ar[i]);
			return 0;
		}
	}
	puts("NO");
}