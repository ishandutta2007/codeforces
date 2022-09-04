//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	LL a[N];
	LL sum=0;
	for(int i=0;i<n;i++)
	scanf("%I64d",&a[i]),sum+=a[i];
	if(sum%2!=0){
		printf("NO\n");
		return 0;
	}
	set<LL> s;
	s.insert(0);
	LL sum1=0;
	sum/=2;
	for(int i=0;i<n;i++){
		sum1+=a[i];
		s.insert(a[i]);
		if(s.find(sum1-sum)!=s.end()){
			printf("YES\n");
			return 0;
		}
	}
	s.clear();
	s.insert(0);
	sum1=0;
	for(int i=n-1;i>=0;i--){
		sum1+=a[i];
		s.insert(a[i]);
		if(s.find(sum1-sum)!=s.end()){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
} 
// 10010
//1 1 2 6 3 8 4 11 5 17 6 15 7 13 8 25 9 22 10 27
//1
//2 4 6 8 10
//3 6 9
//4 2 6 8 10
//5 5 10
//6 2 3 4 6 8 10