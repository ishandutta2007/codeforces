/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=100005;
int n;
char c[maxn];
string ans[maxn];
map<string,int>num;

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	while(gets(c)){
		string s=c;
		if(s=="\\begin{thebibliography}{99}")break;
		rep(i,s.size()){
			if(s[i]!='\\')continue;
			int j;
			string cur="";
			for(j=i+6;s[j]!='}';j++)cur+=s[j];
			num[cur]=++n;
			i=j;
		}
	}
	n=0;
	bool ok=true;
	while(gets(c)){
		string s=c;
		if(s=="\\end{thebibliography}")break;
		string cur="";
		for(int i=9;s[i]!='}';i++)cur+=s[i];
		if(num[cur]!=++n)ok=false;
		ans[num[cur]]=s;
	}
	if(ok)puts("Correct");
	else{
		puts("Incorrect");
		puts("\\begin{thebibliography}{99}");
		REP(i,n)printf("%s\n",ans[i].c_str());
		puts("\\end{thebibliography}");
	}
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/