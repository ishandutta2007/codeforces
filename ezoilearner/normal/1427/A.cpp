#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;
#define Maxn 55 
#define cout cerr
#define FR first
#define SE second
int a[Maxn];
bool cmp(int t1,int t2){return t1>t2;}

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
	int t;rd(t);
	while(t--){
		rd(n);int sum=0;
		for(int i=1;i<=n;++i){
			rd(a[i]);
			sum+=a[i];
		}
		if(sum==0)puts("NO");
		else{
			if(sum<0)sort(a+1,a+n+1);
			else sort(a+1,a+n+1,cmp);
			puts("YES");
			for(int i=1;i<=n;++i)printf("%d ",a[i]);
			puts("");
		}
	}
	return 0;
}