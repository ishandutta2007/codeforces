#include<bits/stdc++.h>
using namespace std;
inline int rd(){int x=0,c=0,f=1;for(;c<'0'||c>'9';c=getchar())f=c!='-';
for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';return f?x:-x;}
const int N=111;
int n,m;
char s[N][N];
bool judge(){
	if(n%3)return 0;
	int t=n/3;
	char a = s[1][1], b = s[t+1][1], c = s[2*t+1][1];
	int o = 3;
	if (a != 'R' && b != 'R' && c != 'R')return 0;
	if (a != 'G' && b != 'G' && c != 'G')return 0;
	if (a != 'B' && b != 'B' && c != 'B')return 0;
	for(int k=1,i=1;k<=3;k++){
		char tmp=s[i][1];
		for(int cc=1;cc<=t;i++,cc++)
			for(int j=1;j<=m;j++)
				if(s[i][j]!=tmp)return 0;
	}
	return 1;
}
bool check(){
	if(m%3)return 0;
	int t=m/3;
	char a = s[1][1], b = s[1][t+1], c = s[1][2*t+1];
	int o = 3;
	if (a != 'R' && b != 'R' && c != 'R')return 0;
	if (a != 'G' && b != 'G' && c != 'G')return 0;
	if (a != 'B' && b != 'B' && c != 'B')return 0;
	for(int k=1,i=1;k<=3;k++){
		char tmp=s[1][i];
		for(int cc=1;cc<=t;i++,cc++)
			for(int j=1;j<=n;j++)
				if(s[j][i]!=tmp)return 0;
	}
	return 1;
}
int main(){
	n=rd(),m=rd();	
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	puts(judge()||check()?"YES":"NO");
}