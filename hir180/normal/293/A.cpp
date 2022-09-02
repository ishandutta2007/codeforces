#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int n;
	string a,b;
	cin >> n;
	cin >> a >> b;
	int r1=0,r2=0;
	int x=0,xy=0,y=0;
	for(int i=0;i<2*n;i++){
		if(a[i]=='0' && b[i]=='1') x++;
		if(a[i]=='1' && b[i]=='0') y++;
		if(a[i]=='1' && b[i]=='1') xy++;
		r1+=a[i]-'0';
		r2+=b[i]-'0';
	}
	int gen0=0,gen1=0;
	if(xy%2==0){
		gen0=gen1=xy/2;
		if(x>y){
			gen0+=(x-y+1)/2;
		}else{
			gen1+=(y-x)/2;
		}
	}
	else{
		gen0=xy/2+1;
		gen1=xy/2;
		if(x<y){
			gen1+=(y-x+1)/2;
		}else{
			gen0+=(x-y)/2;
		}
	}
	r1-=gen1;
	r2-=gen0;
	if(r1<r2){
		puts("Second");
	}else if(r1>r2){
		puts("First");
	}else{
		puts("Draw");
	}
}