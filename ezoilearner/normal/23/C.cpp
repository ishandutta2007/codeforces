#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 200010
#define cout cerr

struct Data{
	int a,b,id;
	bool operator <(const Data &t)const{return a>t.a;}
}data[Maxn];

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
		for(int i=1;i<2*n;++i){
			rd(data[i].a);rd(data[i].b);
			data[i].id=i;
		}
		sort(data+1,data+2*n);
		puts("YES");
		printf("%d ",data[1].id);
		for(int i=2;i<2*n;i+=2)
			if(data[i].b>data[i+1].b)printf("%d ",data[i].id);
			else printf("%d ",data[i+1].id);
		puts("");
	}
	return 0;
}