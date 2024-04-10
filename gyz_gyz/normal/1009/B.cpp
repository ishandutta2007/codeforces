#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 998244353
#define eps 1e-6
using namespace std;
int n,m,u;string s;
int main(){
	cin>>s;n=s.length()-1;
	rep(i,0,n)if(s[i]=='1')m++;
	rep(i,0,n){
		if((!u)&&(s[i]=='2')){
			rep(j,1,m)printf("1");u=1;
		}
		if(s[i]!='1')printf("%c",s[i]);
	}
	if(!u)rep(i,1,m)printf("1");
}