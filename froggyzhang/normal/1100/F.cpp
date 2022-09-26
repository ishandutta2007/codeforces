#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 500010
const int dig=25;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N],m,d[N],ans[N],las[N];
struct QAQ{
	int l,r,id;
}q[N];
bool cmp(QAQ a,QAQ b){
	return a.r<b.r;
} 
void Insert(int x,int p){
	for(int i=dig;i>=0;i--){
		if((x>>i)&1){
			if(!d[i]){
				las[i]=p;
				d[i]=x;
				return;
			} 
			else{
				if(las[i]<p)swap(p,las[i]),swap(x,d[i]);
				x^=d[i];
			}
		}
	}
}
int Query(int lim){
	int ans=0;
	for(int i=dig;i>=0;i--){
		if(lim<=las[i]){
			ans=max(ans,ans^d[i]);
		}
	} 
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	} 
	m=read();
	for(int i=1;i<=m;i++){
		q[i].l=read(),q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int pos=0;
	for(int i=1;i<=m;i++){
		while(pos<q[i].r){
			Insert(a[++pos],pos);
		}
		ans[q[i].id]=Query(q[i].l);
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	} 
	return 0;
}