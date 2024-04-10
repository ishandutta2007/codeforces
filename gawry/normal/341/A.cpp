#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
const int MAX=100000;
int n,a[MAX];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	long long sum=0,p=0,q=n;
	for(int i=0;i<n;i++){
		p+=(long long)a[i]*(i+1)-sum;
		sum+=a[i];
	}
	sum=0;
	for(int i=n-1;i>=0;i--){
		p+=sum-(long long)a[i]*(n-1-i);
		sum+=a[i];
	}
	long long d=gcd(p,q);
	p/=d;
	q/=d;
	cout<<p<<" "<<q<<endl;
}