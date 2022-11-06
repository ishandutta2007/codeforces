#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge*i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const char f0[]="What are you doing at the end of the world? Are you busy? Will you save us?",
f1[]="What are you doing while sending \"",f2[]="\"? Are you busy? Will you send \"",f3[]="\"?";
#define sl(s) strlen(s)
const int l0=sl(f0),l1=sl(f1),l2=sl(f2),l3=sl(f3),N=500000;
int n;ll K,a[N];
char F(int n,ll k){if(!n)return k<=l0?f0[k-1]:'.';if(k<=l1)return f1[k-1];if((k-=l1)<=a[n-1]||!a[n-1])return F(n-1,k);if((k-=a[n-1])<=l2)return f2[k-1];if((k-=l2)<=a[n-1]||!a[n-1])return F(n-1,k);return (k-=a[n-1])<=l3?f3[k-1]:'.';}
int main(){
//	dbg(l0);
	int q=rd();
//	cout<<l0<<" "<<l1<<" "<<l2<<" "<<l3<<endl;
	a[0]=l0;For(i,1,N){a[i]=2*a[i-1]+l1+l2+l3;if(a[i]>1e18)break;}
	while(q--){
		cin>>n>>K;
		putchar(F(n,K));
	}
}