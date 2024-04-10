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
	long long mi,ma;
	scanf("%lld %lld",&mi,&ma);
	vector<long long>a,b;
	while(mi){
		a.pb(mi%2);
		mi/=2;
	}
	reverse(a.begin(),a.end());
	while(ma){
		b.pb(ma%2);
		ma/=2;
	}
	reverse(b.begin(),b.end());
	long long ans=0;
	int as=a.size();
	int bs=b.size();
	long long binary[63];
	binary[0]=1;
	for(int i=1;i<=62;i++){
		binary[i]=binary[i-1]*2;
	}
	if(b.size()!=a.size()){
		for(int i=0;i<bs-as;i++){
			ans+=binary[bs-1-i];
		}
		ans+=binary[as]-1;
		printf("%lld\n",ans);
		return 0;
	}else{
		for(int i=0;i<as;i++){
			if(a[i]!=b[i]){
				printf("%lld\n",binary[as-i]-1);
				return 0;
			}
		}
		puts("0");
	}
}