#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 300000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
char s[N];int n;
int main(){
	scanf("%d",&n);scanf("%s",s+1);
	rep(i,1,n-1){
		if(s[i]>s[i+1]){
			rep(j,i+1,n)printf("%c",s[j]);return 0;
		}
		printf("%c",s[i]);
	}
}