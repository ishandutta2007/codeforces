//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define mod 1000000007
vector<long long>vec;
long long ans=0;
bool used[100005]={};
long long p(long long s,int go){
	int i;
	int so=1;
	for(i=1;;i++){
		so*=2;
		if(so>go){
			break;
		}
	}
	i--;
	long long se[25];
	se[0]=s;
	for(int j=1;j<=i;j++){
		se[j]=se[j-1]*se[j-1];
		se[j]%=mod;
	}
	long long re=1;
	for(int j=0;j<=i;j++){
		if(((go>>j) & 1)){
			re*=se[j];
			re%=mod;
		}
	}
	return re;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		long long int gl;
		scanf("%lld",&gl);
		vec.pb(gl);
	}
	sort(vec.begin(),vec.end());
	int lim=vec[vec.size()-1];
	lim=100000;
	long long res=0;
	for(long long i=1;i<=100000;i++){
		long long gk=i;
		vector<long long>ve;
		int cou=0;
		for(long long j=1;j*j<=i;j++){
			if(gk%j==0){
				if(j*j==i){
					ve.pb(j);
				}else{
					ve.pb(j);
					ve.pb(i/j);
				}
			}
		}
			sort(ve.begin(),ve.end());
			int num[500];
			for(int j=0;j<ve.size();j++){
				num[j]=lower_bound(vec.begin(),vec.end(),ve[j])-vec.begin();
			}
			long long ans=1;
			long long rest=1;
			for(int j=0;j<ve.size()-1;j++){
				ans*=p((long long)j+1,num[j+1]-num[j]);
				if(j!=ve.size()-2) rest*=p((long long)j+1,num[j+1]-num[j]);
				ans%=mod;
				rest%=mod;
			}
			ans*=p((long long)ve.size(),n-num[ve.size()-1]);
			if(ve.size()>1) rest*=p((long long)ve.size()-1,n-num[ve.size()-2]);
			else rest=0;
			ans%=mod; rest%=mod;
			ans-=rest;
			ans+=mod;
			ans%=mod;
			res+=ans;
			res%=mod;
	}
	printf("%lld\n",res);
}