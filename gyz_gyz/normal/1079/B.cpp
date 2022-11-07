#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,x;string s;
int main(){
	cin>>s;n=s.length();
	rep(i,1,5)rep(j,i,20)if(i*j>=n){
		printf("%d %d\n",i,j);
		rep(k,1,i){
			rep(l,1,j)if(l<=(k<=i*j-n))printf("*");
			else printf("%c",s[x++]);printf("\n");
		}
		return 0;
	}
}