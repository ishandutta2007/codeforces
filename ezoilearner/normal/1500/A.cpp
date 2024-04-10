#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

const int N=2500000;
int n;
#define Maxn 2500010
const int T=3200;
int a[200010];
vector<int> vec[Maxn];
pii C[Maxn<<1]; 
int seq[T+10],cnt;

int main(){
	rd(n);
	rep(i,1,n){
		rd(a[i]);
		vec[a[i]].push_back(i);
	}
	int at=0;
	rep(i,1,N)
		if(vec[i].size()>0){
			at++;
			if(at>T)vec[i].clear();
			else seq[++cnt]=i;
		}
	rep(i,1,cnt)
		rep(j,i,cnt){
			int t1=seq[i],t2=seq[j];
			bool flag=true;
			if(t1==t2&&vec[t1].size()<=1)flag=false;
			if(flag){
				if(C[t1+t2].FR){
					puts("YES");
					if(t1!=t2)printf("%d %d %d %d\n",vec[t1][0],vec[t2][0],C[t1+t2].FR,C[t1+t2].SE);
					else printf("%d %d %d %d\n",vec[t1][0],vec[t2][1],C[t1+t2].FR,C[t1+t2].SE);
					return 0;
				}
				if(t1==t2&&vec[t1].size()>=4){
					puts("YES");
					printf("%d %d %d %d\n",vec[t1][0],vec[t1][1],vec[t1][2],vec[t1][3]);
					return 0;
				}	
				if(t1!=t2&&vec[t1].size()>=2&&vec[t2].size()>=2){
					puts("YES");
					printf("%d %d %d %d\n",vec[t1][0],vec[t2][0],vec[t1][1],vec[t2][1]);
					return 0;
				}
				if(t1==t2){
					C[t1+t2]=pii(vec[t1][0],vec[t1][1]);
				}else{
					C[t1+t2]=pii(vec[t1][0],vec[t2][0]);
				}
			}
		}
	puts("NO");
	return 0;
}