#include<set>
#include<map>
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define x first
#define y second
#define N 100005
#define sqrt(x) ((x)*(x))
using namespace std;
typedef long long ll;
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	printf("%d ",(k-1)/(2*m)+1);
	printf("%d ",(k-1)%(2*m)/2+1);
	printf("%c\n",k%2==0?'R':'L');
}
/*
1 2 3 4
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44*/