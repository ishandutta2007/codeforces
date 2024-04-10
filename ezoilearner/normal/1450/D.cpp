#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 300010
#define cout cerr
#define FR first
#define SE second
int a[Maxn],b[Maxn],c[Maxn],ans[Maxn];
int stk[Maxn],tp=0;
set<int> s;
vector<int> to[Maxn]; 
char ch[Maxn];

void calc(int t1,int t2,int id){
	//[0,t1] [0,t2] [1,t1+t2-1]
	if(t1==0||t2==0){
		to[t1+t2+1].push_back(a[id]);
		return;
	}
	ans[2]++;ans[t1+t2+1]--;
	to[t1+t2+1].push_back(a[id]);
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
	int T;rd(T);
	while(T--){
		rd(n);
		s.clear();
		for(int i=1;i<=n+1;++i)to[i].clear();
		memset(ans,0,sizeof(int)*(n+3));
		for(int i=1;i<=n;++i)rd(a[i]);a[0]=a[n+1]=0;
		tp=0;stk[++tp]=0;
		for(int i=1;i<=n;++i){
			while(tp&&a[i]<a[stk[tp]])tp--;
			b[i]=stk[tp];
			stk[++tp]=i;
		}
		tp=0;stk[++tp]=n+1;
		for(int i=n;i>=1;--i){
			while(tp&&a[i]<=a[stk[tp]])tp--;
			c[i]=stk[tp];
			stk[++tp]=i;
			calc(c[i]-i-1,i-b[i]-1,i);
		}
		for(int i=1;i<=n;++i){
			ans[i]+=ans[i-1];
		}
		
		for(int i=n;i>=1;--i){
			bool D=false;
			for(int j=0;j<to[i].size();++j)
				if(s.find(to[i][j])!=s.end()){
					for(int k=i;k>=1;--k)ch[k]='0';
					D=true;
					break;
				}else s.insert(to[i][j]);
			if(D)break;
			if(ans[i])ch[i]='0';
			else{
				set<int>::iterator it=s.end();it--;
				if((*it)!=n-i+1)ch[i]='0';
				else ch[i]='1'; 
			}
		}
		for(int i=1;i<=n;++i)putchar(ch[i]);
		puts("");
	}
}