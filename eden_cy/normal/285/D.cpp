#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)

int val[17]={0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};

int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",val[n]);
	return 0;
}