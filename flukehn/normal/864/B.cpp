#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
char s[210];
bool judge(char x){
	return x>='a'&&x<='z';
}
int main(){
	int n=rd();
	scanf("%s",s+1);
	int mx=0;
	rep(i,1,n){
		if(judge(s[i])) {
			set<char> S;
			rep(j,i,n){
				if(!judge(s[j])) {
					i = j - 1;
					break;
				}
				else S.insert(s[j]); 
			}
			mx=max(mx,(int)S.size());
		}
	}
	cout<<mx<<endl;
}