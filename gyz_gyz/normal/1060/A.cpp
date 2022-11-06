#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 600000
#define ll long long
using namespace std;
int n,m;char s[N];
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	rep(i,1,n)if(s[i]=='8')m++;
	printf("%d",min(m,n/11));	
}