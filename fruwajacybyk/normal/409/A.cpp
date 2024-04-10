#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;


int main(){
	char s[25],s2[25];
	cin>>s;
	cin>>s2;
	int a = 0;
	int b = 0;
	for(int i=0;i<strlen(s);i+=2){
		if(s[i]!=s2[i]){
			if(s[i]=='8' && s2[i]=='[') a++;
			if(s2[i]=='8' && s[i]=='[') b++;
			if(s2[i]=='[' && s[i]=='(') b++;
			if(s2[i]=='(' && s[i]=='[') a++;
			if(s2[i]=='8' && s[i]=='(') a++;
			if(s2[i]=='(' && s[i]=='8') b++;
		}
	}
	if(a>b) printf("TEAM 1 WINS\n");
	if(b>a) printf("TEAM 2 WINS\n");
	if(a==b) printf("TIE\n");


	return 0;
}