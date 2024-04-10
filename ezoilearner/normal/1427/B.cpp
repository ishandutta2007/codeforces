#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
#define Maxn 100010 
#define cout cerr
#define FR first
#define SE second
char ch[Maxn];

struct Data{
	int l,r;
	bool operator <(const Data &t)const{
		return r-l<t.r-t.l;
	}
}data[Maxn];int cnt=0;

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
		rd(n);int K;rd(K);
		scanf("%s",ch+1);
		int lst=0;cnt=0;int s1=0,s2=0;
		for(int i=1;i<=n;++i)
			if(ch[i]=='W'){
				if(!s1)s1=i;
				s2=i;
				lst=i;
			}else{
				if(i<n&&ch[i]=='L'&&ch[i+1]=='W'&&lst)data[++cnt]=(Data){lst+1,i};
			}
		sort(data+1,data+cnt+1);
		for(int i=1;i<=cnt&&K;++i){
			for(int j=data[i].l;K&&j<=data[i].r;++j){
				ch[j]='W';K--;
			}
		}
		if(!s1){
			for(int i=1;i<=min(n,K);++i)ch[i]='W';
		}else{
			for(int i=s1-1;i>=1&&K;--i){
				K--;
				ch[i]='W';
			}
			for(int i=s2+1;i<=n&&K;++i){
				ch[i]='W';
				K--;
			}
		}
		int res=0;
		for(int i=1;i<=n;++i)
		if(ch[i]=='W'){
			res++;
			if(i>1&&ch[i-1]=='W')res++;
		}
		printf("%d\n",res);
	}
	return 0;
}