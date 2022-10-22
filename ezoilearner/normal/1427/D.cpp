#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
#define Maxn 55
#define cout cerr
#define FR first
#define SE second
int seq[Maxn][Maxn],len[Maxn],cnt=0;
int p[Maxn];
int b[Maxn];

void calc(int *A,int k){
	int at=0,s=n;
	for(int i=k;i>=1;--i){
		for(int j=s-A[i]+1;j<=s;++j)b[++at]=p[j];
		s-=A[i];
	}
	for(int i=1;i<=n;++i)p[i]=b[i];
}

void solve(){
	cnt=0;
	int l,r,t;
	for(int i=1;i<=n;++i){
		if(p[i]==1){
			l=r=i;t=0;
			break;
		}
	}
	for(int i=2;i<=n;++i){
		cnt++;
		int at;
		for(int j=1;j<=n;++j)
			if(p[j]==i){
				at=j;
				break;
			}
		if(at>r){
			int &L=len[cnt];
			if(at<n)seq[cnt][++L]=n-at;
			seq[cnt][++L]=at-r;
			if(t)seq[cnt][++L]=r-l+1;
			else{
				for(int i=r;i>=l;--i)seq[cnt][++L]=1;
			}
			if(l>1)seq[cnt][++L]=l-1;
			l=n-r;r=l+i-1;
			t=1;
		}else{
			int &L=len[cnt];
			if(r<n)seq[cnt][++L]=n-r;
			if(!t)seq[cnt][++L]=r-l+1;
			else{
				for(int i=l;i<=r;++i)seq[cnt][++L]=1;
			}
			seq[cnt][++L]=l-at;
				if(at>1)seq[cnt][++L]=at-1;
			l=n-r+1;r=l+i-1;
			t=0;
		}
		reverse(seq[cnt]+1,seq[cnt]+len[cnt]+1);
		calc(seq[cnt],len[cnt]);
	}
	if(t){
		cnt++;
		len[cnt]=n;
		for(int i=1;i<=n;++i)seq[cnt][i]=1;
	}
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
		rd(n);
		if(n==1){
			puts("0");
			return 0;
		}
		for(int i=1;i<=n;++i)rd(p[i]);
		solve();
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i){
			printf("%d ",len[i]);for(int j=1;j<=len[i];++j)printf("%d ",seq[i][j]);
			puts("");
		}
	return 0;
}