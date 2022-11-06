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
int n,ok[30];char s[200];
int main(){
	ok[0]=ok['o'-'a']=ok['u'-'a']=
	ok['i'-'a']=ok['e'-'a']=1;
	ok['n'-'a']=2;scanf("%s",s);
	for(;s[n];n++)
		if((!ok[s[n]-'a'])&&((!s[n+1])||(ok[s[n+1]-'a']!=1))){
			printf("NO");return 0;
		}
	printf("YES");
}