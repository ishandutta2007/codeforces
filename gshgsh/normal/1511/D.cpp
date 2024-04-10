#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int N,K,M,a[26*26];int main(){cin>>N>>K;For(i,0,K-1){a[M++]=i;For(j,1,K-i-1)a[M++]=i,a[M++]=i+j;}For(i,0,N-1)putchar(a[i%M]+'a');return 0;}